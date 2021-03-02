# labuladong���㷨С�������������ܽ�

*���ں�*
![https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490273&idx=1&sn=f4e68b429830da44872f531c06204ea3&chksm=9bd7e4e9aca06dff6cbe3839e8ad427594d011674a228e346861684e7424325ab4bb5ccc0767&scene=126&sessionid=1608949878&key=3172bc5cb08cf550e1ad7e3e25ea14e198750f66fe04bd827afbfe82596230980ff9d5d9579f3924e2d60f57404d9be45930e1637ba03f142f355207cbad0fd242fffd1465d34028b693deefe130f444c7b3181eeea2be4949ecc20def07f3ab8a43772c36b955e297a64e90b452a131941ef835dc70fe217d3f97168610f6c1&ascene=1&uin=MTU5OTQ2ODIwMw%3D%3D&devicetype=Windows+10+x64&version=6300002f&lang=zh_CN&exportkey=A68HaGz9Aj9QvYS%2FFTcEC3Q%3D&pass_ticket=p4OILhQhDVnCroE2lBkbw9H1tjtbC2JuRWQyCEG1wJ5FSM1uRs8MkF10XZFPHXfJ&wx_header=0]

## ��

### ����һ�ö����������л�һ�ö�������

��Ӧleetcode��Ŀ��652.Ѱ���ظ�������
![https://leetcode-cn.com/problems/find-duplicate-subtrees/]

��Ҫ֪�����Լ�Ϊ����������ɶ�����ǲ��ǵ���֪���ҵ�����������ɶ�����ټ����Լ����͹�������������������,���ǣ���Ҫ��*�������*

- ����һ�����ķ�����
    1. **����ͨ��ƴ���ַ����ķ�ʽ�Ѷ��������л�**��ͨ��������������
    2. �÷����ֵ������`#`��ʾ��ָ�룬�������ַ�`,`�ָ�ÿ���������ڵ�ֵ�����������л�����������·

```c++
void traverse(TreeNode root) {
    traverse(root.left);
    traverse(root.right);
    /* �ⷨ�����λ�� */
}
// Ʃ��������Ľ��
int count(TreeNode root) {
    if (root == null) {
        return 0;
    }
    // ��������������ж��ٽڵ�
    int left = count(root.left);
    int right = count(root.right);
    /* �����������λ�� */
    // �����Լ����������ö������Ľڵ���
    int res = left + right + 1;
    return res;
}
//ͨ��ƴ���ַ����ķ�ʽ�Ѷ��������л�
String traverse(TreeNode root) {
    // ���ڿսڵ㣬������һ�������ַ���ʾ
    if (root == null) {
        return "#";
    }
    // �������������л����ַ���
    String left = traverse(root.left);
    String right = traverse(root.right);
    /* �����������λ�� */
    // �������������Լ����������Լ�Ϊ���Ķ��������л����
    String subTree = left + "," + right + "," + root.val;
    return subTree;
}
```

### RB-Tree

�������һ�ָ�������ƽ���BST����ɾ��ĵĸ��Ӷȶ���`O(logN)`


### ��BST��������������������

��Ӧleetcode��Ŀ��230. �����������е�KС��Ԫ��
![https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/]

���ʣ�BST�ĸ�����ֵ���������ӵ�ֵ����С�����Һ��ӵ�ֵ��**BST�����������һ�����������** 
        ���� -> �� �� ��
        ���� -> �� �� ��

- ��ô�ص�������⣬���ҵ���kС��Ԫ�أ�����˵�ҵ�����Ϊk��Ԫ�أ������ﵽ���������Ӷȣ��ؼ�Ҳ����ÿ���ڵ��֪�����Լ��ŵڼ�������˵�����Ҳ�������Ϊk��Ԫ�أ���ǰ�ڵ�֪���Լ�������m����ô�ҿ��ԱȽ�m��k�Ĵ�С��
    1. ���m == k����Ȼ�����ҵ��˵�k��Ԫ�أ����ص�ǰ�ڵ�����ˡ�
    2. ���k < m����˵��������k��Ԫ���������������Կ���ȥ������������k��Ԫ�ء�
    3. ���k > m����˵��������k��Ԫ���������������Կ���ȥ������������k - m - 1��Ԫ�ء�
�����Ϳ��Խ�ʱ�临�ӶȽ���O(logN)�ˡ�

�����ù�ϣ��memo����¼��Ӧ�Ľڵ��У����Լ�Ϊ������ö������ж��ٸ��ڵ㡣

�ڶ������ݹ���֮�ϣ���չ��һ�� BST �����ܣ�
```c++
void BST(TreeNode root, int target) {
    if (root.val == target)
        // �ҵ�Ŀ�꣬����ʲô
    if (root.val < target) 
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
}
```

### ��֤BST

��Ӧleetcode��Ŀ��98. ��֤����������
![https://leetcode-cn.com/problems/validate-binary-search-tree/]

*�������֤��ʽ������ֻ����֤ÿ���ڵ��Լ��������Һ��ӵĹ�ϵ��ȴ���ܰ��Լ��Ĵ�СԼ�����ݸ��������ӱ�*
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

*��ȷ����֤��ʽ��ͨ��ʹ�ø������������Ӻ��������б��ڲ�����Я��������Ϣ��������Լ�����ݸ����������нڵ�*
```c++
bool isValidBST(TreeNode root) {
    return isValidBST(root, null, null);
}
/* �޶��� root Ϊ���������ڵ�������� max.val > root.val > min.val */
bool isValidBST(TreeNode root, TreeNode min, TreeNode max) {
    // base case
    if (root == null) return true;
    // �� root.val ������ max �� min �����ƣ�˵�����ǺϷ� BST
    if (min != null && root.val <= min.val) return false;
    if (max != null && root.val >= max.val) return false;
    // �޶������������ֵ�� root.val������������Сֵ�� root.val
    return isValidBST(root.left, min, root) 
        && isValidBST(root.right, root, max);
}
```

### �Զ����������Ľڵ㴦��

��Ӧleetcode��Ŀ��700. �����������е�����
![https://leetcode-cn.com/problems/search-in-a-binary-search-tree/]

����BST�����ʣ������һ�ױ���BST�Ŀ�ܣ�
```c++
void BST(TreeNode root, int target) {
    if (root.val == target)
        // �ҵ�Ŀ�꣬����ʲô
    if (root.val < target) 
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
}
```

### BST �Ĳ����ɾ�� 

��Ӧleetcode��Ŀ��701. �����������еĲ������  && 450. ɾ�������������еĽڵ�
![https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/]
![https://leetcode-cn.com/problems/delete-node-in-a-bst/]

- ���� 
    �����λ����`NULL`������Ҫ���úö��������������ʣ�BST�����λ�ò�һ������ײ㣬��һ����null��λ��

```c++
TreeNode deleteNode(TreeNode root, int key) {
    if (root.val == key) {
        // �ҵ���������ɾ��
    } else if (root.val > key) {
        // ȥ��������
        root.left = deleteNode(root.left, key);
    } else if (root.val < key) {
        // ȥ��������
        root.right = deleteNode(root.right, key);
    }
    return root;
}
```

- ɾ��
    ���ҵ�����ڵ㣬Ȼ������������ڵ㣺
        1. �����0�����ӣ�ֱ��ɾ����
        2. �����1�����ӣ����Ǹ���������Լ���
        3. ������������ӣ����Լ��ĺ�̽ڵ��ֵ������Լ���Ȼ��ɾ���Ǹ���̽ڵ㡣

```c++
TreeNode deleteNode(TreeNode root, int key) {
    if (root == null) return null;
    if (root.val == key) {
        // ������ if ����� 1 �� 2 ����ȷ������
        if (root.left == null) return root.right;
        if (root.right == null) return root.left;
        // ������� 3
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
    // BST ����ߵľ�����С��
    while (node.left != null) node = node.left;
    return node;
} 
```

### �����������л�

��Ӧleetcode��Ŀ��297. �����������л��ͷ����л�
![https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/]

*���л�*�ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ������������Խ�ת��������ݴ洢��һ���ļ������ڴ��У�ͬʱҲ����ͨ�����紫�䵽��һ���������������ȡ�෴��ʽ�ع��õ�ԭ���ݡ�

���л��������ķ�ʽ�У�ǰ�����������������������

���л���ʵ�ֺ����ף�ǰ�����򡢺������������ʵ�ֽ����������л���ֻ�ǶԸ��ڵ㴦���λ�ò�ͬ���ѡ�
�����и���Ҫע��ĵط��ǣ�*�������*������У����޷������л�Ϊԭʼ�����ṹ����Ϊ���޷��ҵ����ڵ㣡����

ǰ��������л���Ҫǰ��������ָ����������Ҳһ����������������л��ͷ����л���Ҫ�õ�������

**�ַ�������Ϊ�ַ������һ������**
```c++
// string -> data;
std::stringstream ss;
std::string item;
queue<string> q;
while(std::getline(ss, item, '_'))
    q.push(item);
// �ַ�����ss
// string����Ԫ�أ�item
// ��'_'���綨
```

**string <---> int**
int To string : string_val = std::to_string(int_val);
string To int : int_val = stoi(string_val);  

or
string TO int : int_val = atoi(string_val.c_str());



## λ����

### ����һ�����е� 1 ��λ��

n = n & (n - 1);
��һ��������ȥ1֮���ٺ�ԭ����������λ�����㣬�õ��Ľ���൱���ǰ������Ķ����Ʊ�ʾ�е����ұ�һ��1���0��
�ܶ���������ⶼ�����ô˷������


## ����

### ����ָ��

����������⵱һ��ָ�벻�ܹ�ʱ��������������һ����ָ���������
һ��ָ���һ��һ��ָ����һ��
������һ��ָ�������Ȼ���ٳ�����һ��ָ��

## ����

### ����

���Ҳ�������׵ķ���ʱ���ַ��������������

��֪������nλ��������Ҫn+1λ���ַ��������һλ��'\0'


