# -*- coding: utf-8 -*-
"""Breast_Cancer_Prediction_NEHARIKA.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/143lB4kEtcZQj6p07MHOYhW-5aGDic3ny
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from google.colab import files
uploaded=files.upload()

df=pd.read_csv('data.csv')

df.head(10)

#counting number of rows and columns in dataset
df.shape

#count number of empty values in each column
df.isna().sum()

df=df.dropna(axis=1)

df.shape

#getting the count of number of Malognant (M) or Benign (B) cells
df['diagnosis'].value_counts()

#visualization of the count
sns.countplot(df['diagnosis'],label='count')

df.dtypes

#encode the categorical data values
from sklearn.preprocessing import LabelEncoder
labelencoder_Y=LabelEncoder()
df.iloc[:,1]= labelencoder_Y.fit_transform(df.iloc[:,1].values)

#create a pair plot
sns.pairplot(df.iloc[:,1:5], hue='diagnosis')

#printing the first 5 rows of new data
df.head(5)

#get the correlation of columns
df.iloc[:,1:12].corr()

#visualizing
sns.heatmap(df.iloc[:,1:12].corr(),annot=True,fmt='.0%')

#splitting the data set into independant (X) and dependant (Y) dataset
X=df.iloc[:,2:31].values
Y=df.iloc[:,1].values

#splitting the dataset into 75% training and 25% testing
from sklearn.model_selection import train_test_split
X_train,X_test,Y_train,Y_test=train_test_split(X,Y,test_size=0.25 ,random_state=0)

#scalling the data(feature scaling)
from sklearn.preprocessing import StandardScaler
sc=StandardScaler()
X_train=sc.fit_transform(X_train)
X_test=sc.fit_transform(X_test)

#creating a function for the models:
def models(X_train,Y_train):
  #logistic regression
  from sklearn.linear_model import LogisticRegression
  log=LogisticRegression(random_state=0)
  log.fit(X_train,Y_train)

  #decision tree
  from sklearn.tree import DecisionTreeClassifier
  tree=DecisionTreeClassifier(criterion='entropy',random_state=0)
  tree.fit(X_train,Y_train)

  #random Forest classifier
  from sklearn.ensemble import RandomForestClassifier
  forest=RandomForestClassifier(n_estimators=10,criterion='entropy',random_state=0)
  forest.fit(X_train,Y_train)

  #printing all models accuracy on training data
  print('[0]Logistic Regression Training Accuracy:',log.score(X_train,Y_train))
  print('[1]Decision Tree Classifier Training Accuracy:',tree.score(X_train,Y_train))
  print('[2]Random Forest Classifier Training Accuracy:',forest.score(X_train,Y_train))

  return log,tree,forest

#getting all of the models
model=models(X_train,Y_train)

#test model accuracy on test data on confusion matrix
from sklearn.metrics import confusion_matrix

for i in range( len(model) ):
  print('Model',i)
  cm=confusion_matrix(Y_test,model[0].predict(X_test))

  TP= cm[0][0]
  TN= cm[1][1]
  FN= cm[1][0]
  FP= cm[0][1]
  print(cm)
  print('Testing Accuracy=' ,(TP+TN)/(TP+TN+FN+FP))
  print()

#another way to get metrics of the model
from sklearn.metrics import classification_report
from sklearn.metrics import accuracy_score
for i in range( len(model) ):
  print('Model',i)
  print(classification_report(Y_test,model[i].predict(X_test)))
  print(accuracy_score(Y_test,model[i].predict(X_test)))
  print()

#print the prediction of random forest classifier model
pred=model[2].predict(X_test)
print(pred)
print()
print(Y_test)