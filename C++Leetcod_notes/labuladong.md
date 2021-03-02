# labuladong的算法小抄——方法论总结

*公众号*
![https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490273&idx=1&sn=f4e68b429830da44872f531c06204ea3&chksm=9bd7e4e9aca06dff6cbe3839e8ad427594d011674a228e346861684e7424325ab4bb5ccc0767&scene=126&sessionid=1608949878&key=3172bc5cb08cf550e1ad7e3e25ea14e198750f66fe04bd827afbfe82596230980ff9d5d9579f3924e2d60f57404d9be45930e1637ba03f142f355207cbad0fd242fffd1465d34028b693deefe130f444c7b3181eeea2be4949ecc20def07f3ab8a43772c36b955e297a64e90b452a131941ef835dc70fe217d3f97168610f6c1&ascene=1&uin=MTU5OTQ2ODIwMw%3D%3D&devicetype=Windows+10+x64&version=6300002f&lang=zh_CN&exportkey=A68HaGz9Aj9QvYS%2FFTcEC3Q%3D&pass_ticket=p4OILhQhDVnCroE2lBkbw9H1tjtbC2JuRWQyCEG1wJ5FSM1uRs8MkF10XZFPHXfJ&wx_header=0]

## 树

### 描述一棵二叉树（序列化一棵二叉树）

对应leetcode题目：652.寻找重复的子树
![https://leetcode-cn.com/problems/find-duplicate-subtrees/]

我要知道以自己为根的子树长啥样，是不是得先知道我的左右子树长啥样，再加上自己，就构成了整棵子树的样子,于是，就要用*后序遍历*

- 描述一棵树的方法：
    1. **可以通过拼接字符串的方式把二叉树序列化**，通过后序遍历来完成
    2. 用非数字的特殊符`#`表示空指针，并且用字符`,`分隔每个二叉树节点值，这属于序列化二叉树的套路

```c++
void traverse(TreeNode root) {
    traverse(root.left);
    traverse(root.right);
    /* 解法代码的位置 */
}
// 譬如计算树的结点
int count(TreeNode root) {
    if (root == null) {
        return 0;
    }
    // 先算出左右子树有多少节点
    int left = count(root.left);
    int right = count(root.right);
    /* 后序遍历代码位置 */
    // 加上自己，就是整棵二叉树的节点数
    int res = left + right + 1;
    return res;
}
//通过拼接字符串的方式把二叉树序列化
String traverse(TreeNode root) {
    // 对于空节点，可以用一个特殊字符表示
    if (root == null) {
        return "#";
    }
    // 将左右子树序列化成字符串
    String left = traverse(root.left);
    String right = traverse(root.right);
    /* 后序遍历代码位置 */
    // 左右子树加上自己，就是以自己为根的二叉树序列化结果
    String subTree = left + "," + right + "," + root.val;
    return subTree;
}
```

### RB-Tree

红黑树是一种改良的自平衡的BST，增删查改的复杂度都是`O(logN)`


### 在BST（二叉搜索树）中搜索

对应leetcode题目：230. 二叉搜索树中第K小的元素
![https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/]

性质：BST的根结点的值大于其左孩子的值，且小于其右孩子的值，**BST的中序遍历是一个升序的序列** 
        升序 -> 左 中 右
        降序 -> 右 中 左

- 那么回到这个问题，想找到第k小的元素，或者说找到排名为k的元素，如果想达到对数级复杂度，关键也在于每个节点得知道他自己排第几。比如说你让我查找排名为k的元素，当前节点知道自己排名第m，那么我可以比较m和k的大小：
    1. 如果m == k，显然就是找到了第k个元素，返回当前节点就行了。
    2. 如果k < m，那说明排名第k的元素在左子树，所以可以去左子树搜索第k个元素。
    3. 如果k > m，那说明排名第k的元素在右子树，所以可以去右子树搜索第k - m - 1个元素。
这样就可以将时间复杂度降到O(logN)了。

可以用哈希表memo来记录对应的节点中，以自己为根的这棵二叉树有多少个节点。

在二叉树递归框架之上，扩展出一套 BST 代码框架：
```c++
void BST(TreeNode root, int target) {
    if (root.val == target)
        // 找到目标，做点什么
    if (root.val < target) 
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
}
```

### 验证BST

对应leetcode题目：98. 验证二叉搜索树
![https://leetcode-cn.com/problems/validate-binary-search-tree/]

*错误的验证方式：这里只能验证每个节点以及它的左右孩子的关系，却不能把自己的大小约束传递给它的孙子辈*
```c++
bool isValidBST(TreeNode root) {
    if (root == null) return true;
    if (root.left != null && root.val <= root.left.val)
        return false;
    if (root.right != null && root.val >= root.right.val)
        return false;
    return isValidBST(root.left)
        && isValidBST(root.right);
}
```

*正确的验证方式：通过使用辅助函数，增加函数参数列表，在参数中携带额外信息，将这种约束传递给子树的所有节点*
```c++
bool isValidBST(TreeNode root) {
    return isValidBST(root, null, null);
}
/* 限定以 root 为根的子树节点必须满足 max.val > root.val > min.val */
bool isValidBST(TreeNode root, TreeNode min, TreeNode max) {
    // base case
    if (root == null) return true;
    // 若 root.val 不符合 max 和 min 的限制，说明不是合法 BST
    if (min != null && root.val <= min.val) return false;
    if (max != null && root.val >= max.val) return false;
    // 限定左子树的最大值是 root.val，右子树的最小值是 root.val
    return isValidBST(root.left, min, root) 
        && isValidBST(root.right, root, max);
}
```

### 对二叉搜索树的节点处理

对应leetcode题目：700. 二叉搜索树中的搜索
![https://leetcode-cn.com/problems/search-in-a-binary-search-tree/]

利用BST的性质，抽象出一套遍历BST的框架：
```c++
void BST(TreeNode root, int target) {
    if (root.val == target)
        // 找到目标，做点什么
    if (root.val < target) 
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
}
```

### BST 的插入和删除 

对应leetcode题目：701. 二叉搜索树中的插入操作  && 450. 删除二叉搜索树中的节点
![https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/]
![https://leetcode-cn.com/problems/delete-node-in-a-bst/]

- 插入 
    插入的位置是`NULL`，并且要利用好二叉搜索树的性质，BST插入的位置不一定是最底层，但一定是null的位置

```c++
TreeNode deleteNode(TreeNode root, int key) {
    if (root.val == key) {
        // 找到啦，进行删除
    } else if (root.val > key) {
        // 去左子树找
        root.left = deleteNode(root.left, key);
    } else if (root.val < key) {
        // 去右子树找
        root.right = deleteNode(root.right, key);
    }
    return root;
}
```

- 删除
    先找到这个节点，然后找它的替代节点：
        1. 如果有0个孩子，直接删除；
        2. 如果有1个孩子，用那个孩子替代自己；
        3. 如果有两个孩子，找自己的后继节点的值来替代自己，然后删掉那个后继节点。

```c++
TreeNode deleteNode(TreeNode root, int key) {
    if (root == null) return null;
    if (root.val == key) {
        // 这两个 if 把情况 1 和 2 都正确处理了
        if (root.left == null) return root.right;
        if (root.right == null) return root.left;
        // 处理情况 3
        TreeNode minNode = getMin(root.right);
        root.val = minNode.val;
        root.right = deleteNode(root.right, minNode.val);
    } else if (root.val > key) {
        root.left = deleteNode(root.left, key);
    } else if (root.val < key) {
        root.right = deleteNode(root.right, key);
    }
    return root;
}
TreeNode getMin(TreeNode node) {
    // BST 最左边的就是最小的
    while (node.left != null) node = node.left;
    return node;
} 
```

### 二叉树的序列化

对应leetcode题目：297. 二叉树的序列化和反序列化
![https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/]

*序列化*是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

序列化二叉树的方式有：前序遍历、后序遍历、层序遍历

序列化的实现很容易，前序、中序、后序遍历都可以实现将二叉树序列化，只是对根节点处理的位置不同而已。
但是有个需要注意的地方是：*中序遍历*后的序列，是无法反序列化为原始的树结构，因为它无法找到根节点！！！

前序遍历序列化就要前序遍历来恢复，后序遍历也一样，而层序遍历序列化和反序列化都要用到队列啦

**字符串划分为字符数组的一个方法**
```c++
// string -> data;
std::stringstream ss;
std::string item;
queue<string> q;
while(std::getline(ss, item, '_'))
    q.push(item);
// 字符串：ss
// string序列元素：item
// 用'_'来界定
```

**string <---> int**
int To string : string_val = std::to_string(int_val);
string To int : int_val = stoi(string_val);  

or
string TO int : int_val = atoi(string_val.c_str());



## 位运算

### 计算一个数中的 1 的位数

n = n & (n - 1);
把一个整数减去1之后再和原来的整数做位与运算，得到的结果相当于是把整数的二进制表示中的最右边一个1变成0。
很多二进制问题都可以用此方法解决


## 链表

### 快慢指针

解决链表问题当一个指针不能够时，用两个步进不一样的指针来解决：
一个指针快一点一个指针慢一点
或先让一个指针出发，然后再出发另一个指针

## 其他

### 大数

最常用也是最容易的方法时用字符串或数组表达大数

已知大数是n位，我们需要n+1位的字符串，最后一位是'\0'


