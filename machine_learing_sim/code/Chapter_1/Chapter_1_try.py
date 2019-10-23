import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression

df_train = pd.read_csv('../Datasets/Breast-Cancer/breast-cancer-train.csv')
df_test = pd.read_csv('../Datasets/Breast-Cancer/breast-cancer-test.csv')

df_test_negative = df_test.loc[df_test['Type'] == 0][['Clump Thickness', 'Cell Size']]
df_test_positive = df_test.loc[df_test['Type'] == 1][['Clump Thickness', 'Cell Size']]

intercept = np.random.random([1])
coef = np.random.random([2])
lx = np.arange(0, 12)
ly = (-intercept - lx * coef[0]) / coef[1]

plt.plot(lx, ly, c='blue')
plt.scatter(df_test_negative['Clump Thickness'],df_test_negative['Cell Size'], marker = 'o', s=200, c='red')
plt.scatter(df_test_positive['Clump Thickness'],df_test_positive['Cell Size'], marker = 'x', s=150, c='black')
plt.xlabel('Clump Thickness yuan')
plt.ylabel('Cell Size yuan')
plt.show()

epochs = 5

for e in range(epochs):
    lr = LogisticRegression()
    lr.fit(df_train[['Clump Thickness', 'Cell Size']][:100], df_train['Type'][:100])
    print 'Testing accuracy (100 training samples):', lr.score(df_test[['Clump Thickness', 'Cell Size']], df_test['Type'])
    intercept = lr.intercept_
    coef = lr.coef_[0, :]
    
    ly = (-intercept - lx * coef[0]) / coef[1]

    plt.plot(lx, ly, c='green')
    plt.scatter(df_test_negative['Clump Thickness'],df_test_negative['Cell Size'], marker = 'o', s=200, c='red')
    plt.scatter(df_test_positive['Clump Thickness'],df_test_positive['Cell Size'], marker = 'x', s=150, c='black')
    xlabel = 'Clump Thickness ' + str(e)
    ylabel = 'Cell Size '+ str(e)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.show()
    
