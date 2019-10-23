#!/usr/bin/env python
# coding: utf-8

import pandas as pd
# 调用pandas工具包的read_csv函数/模块，传入训练文件和测试文件的地址参数，获得返回的数据并存于变量
df_train = pd.read_csv('../Datasets/Breast-Cancer/breast-cancer-train.csv')
df_test = pd.read_csv('../Datasets/Breast-Cancer/breast-cancer-test.csv')
# 选取'Clump Thickness'与'Cell Size'作为特征，构建测试集中的正负分类样本
# .loc()是按行扫描函数，通过行标签Type来索引'Clump Thickness'和'Cell Size'
df_test_negative = df_test.loc[df_test['Type'] == 0][['Clump Thickness', 'Cell Size']]
df_test_positive = df_test.loc[df_test['Type'] == 1][['Clump Thickness', 'Cell Size']]



import matplotlib.pyplot as plt
# 绘制图良性与恶性肿瘤样本点，自变量、因变量、符号、符号大小、符号颜色
plt.scatter(df_test_negative['Clump Thickness'],df_test_negative['Cell Size'], marker = 'o', s=200, c='red')
plt.scatter(df_test_positive['Clump Thickness'],df_test_positive['Cell Size'], marker = 'x', s=150, c='black')
# 绘制横纵坐标
plt.xlabel('Clump Thickness')
plt.ylabel('Cell Size')
# 打印图片
plt.show()




import numpy as np
# 随机生成一个只有一个元素的数组，大小0到1
intercept = np.random.random([1])
# 随机生成一个1*2的数组，大小0到1
coef = np.random.random([2])
# 绘制横坐标长度与纵坐标曲线(直线)
lx = np.arange(0, 12)
ly = (-intercept - lx * coef[0]) / coef[1]
# 打印直线，直线颜色是黄色
plt.plot(lx, ly, c='yellow')

# 绘制图良性与恶性肿瘤样本点，自变量、因变量、符号、符号大小、符号颜色
plt.scatter(df_test_negative['Clump Thickness'],df_test_negative['Cell Size'], marker = 'o', s=200, c='red')
plt.scatter(df_test_positive['Clump Thickness'],df_test_positive['Cell Size'], marker = 'x', s=150, c='black')
plt.xlabel('Clump Thickness')
plt.ylabel('Cell Size')
# 要有以下命令才能打印出图片
plt.show()



from sklearn.linear_model import LogisticRegression
lr = LogisticRegression()
# 导入sklearn中的逻辑斯蒂回归分类器
# 使用前10条训练样本学习直线的系数和截距
# 训练数据是Clump Thickness和Cell Size，训练标签是Type，分别都是10个
lr.fit(df_train[['Clump Thickness', 'Cell Size']][:10], df_train['Type'][:10])
# 直接调用分类器的.score()函数可以返回准确率
print 'Testing accuracy (10 training samples):', lr.score(df_test[['Clump Thickness', 'Cell Size']], df_test['Type'])




intercept = lr.intercept_
coef = lr.coef_[0, :]
ly = (-intercept - lx * coef[0]) / coef[1]
# 将训练出来的直线参数系数重新绘制曲线(直线)作为线性分类器
plt.plot(lx, ly, c='green')
# 将直线内容放到图表上
# 再次绘制测试数据样本，查看对比线性分类器是否有改善增强
plt.scatter(df_test_negative['Clump Thickness'],df_test_negative['Cell Size'], marker = 'o', s=200, c='red')
plt.scatter(df_test_positive['Clump Thickness'],df_test_positive['Cell Size'], marker = 'x', s=150, c='black')
plt.xlabel('Clump Thickness')
plt.ylabel('Cell Size')
plt.show()


# 以下代码就是再训练一次，就是通常是通常所说的第二代目
lr = LogisticRegression()
lr.fit(df_train[['Clump Thickness', 'Cell Size']], df_train['Type'])
print 'Testing accuracy (all training samples):', lr.score(df_test[['Clump Thickness', 'Cell Size']], df_test['Type'])

intercept = lr.intercept_
coef = lr.coef_[0, :]
ly = (-intercept - lx * coef[0]) / coef[1]

plt.plot(lx, ly, c='blue')
plt.scatter(df_test_negative['Clump Thickness'],df_test_negative['Cell Size'], marker = 'o', s=200, c='red')
plt.scatter(df_test_positive['Clump Thickness'],df_test_positive['Cell Size'], marker = 'x', s=150, c='black')
plt.xlabel('Clump Thickness')
plt.ylabel('Cell Size')
plt.show()




