#!/usr/bin/env python
# coding: utf-8

# In[1]:


#Done by SANJAY MALLASAMUDRAM SANTHANAM ; USC ID:3124715393
import pandas as pd
import numpy as np
import math


# In[2]:


#read data 
data=pd.read_csv('C:/Users/Lenovo/Desktop/data.txt', sep=", ", header=None,names=['Occupied', 'Price', 'Music', 'Location', 'VIP', 'Favorite Beer', 'Enjoy'])


# In[3]:


data.head()


# In[4]:


#since file is .txt , remove 1st row. Headers defined manually. 
data=data.drop(data.index[0])


# In[5]:


#remove row number from 1st attribute and semicolon from last attribute. Since separator was comma, these have to be manually removed.
for i in range(0,len(data)):
    data["Occupied"].values[i]=data["Occupied"].values[i].split(":")[1]
    data["Enjoy"].values[i]=data["Enjoy"].values[i].split(";")[0]
#remove white speaces from all attributes.
for i in data.columns:
    data[i]=data[i].str.strip()


# In[6]:


#converted the data to required format after applying necessary pre-processing
data.head()


# In[7]:


#function to calculat entropy. 
def ent(data):
    #count diff value of attributes in final attribute i.e. label attribute. 
    label_count=data[data.columns[-1]].value_counts(normalize=True)
    en=0
    for i in label_count:
        #to prevent math error(domain error) when performing log operation, if the value is 0, we skip it as adding 0 doesnt make any differene 
        if(i==0):
            continue
        en+=-1*i*math.log2(i)
    return en
    


# In[8]:


#given data, returns the best attribute to split data. ie. returns attribute with lowest entropy.
#calculating information gain is redundant once we find entropy because we just subtract entropy value form a constant value.
#instead of subtracting entropy and choosing the highest Information gain, we can choose lowest entropy without subtracting as both methods give same result. 

def best(data):
    cols=data.columns
    #choose all columns except last label attribute.
    cols=cols[:-1]
    best_col=''
    #entropy value cant exceed 1 so initial value set as 2
    min_val=2
    for col in cols:
        e=0
        #find the fractional count of occurrence of each attribute.
        s=data[col].value_counts(normalize=True)
        for v in s.index:
            #choose row with specific value. 
            temp=data[data[col]==v]
            e+=(s[v]*ent(temp))
        #if current entripy value is lower than minimum entropy value so far calculated
        if(e<min_val):
            min_val=e
            best_col=col
        #print(col,e)
    #print(data)
    return best_col
            
    


# In[9]:


#this function selects the most common output value among a set of examples
def plur(data):
    #return label with maximum occurence
    return data[data.columns[-1]].max()


# In[10]:


def dec_tree(data,attr,parent_data):
    #if all attributes are explored i.e. only label column is left, return most common label value
    if(len(attr)==1):
        return plur(data)
    #if all data rows are explored, return most common label of parent_data i.e. data before splitting attribute.
    elif(len(data)==0):
        return plur(parent_data)
    #if labels of data are the same, return the label i.e. check if it is a leaf node. 
    elif(len(data[data.columns[-1]].value_counts())==1):
        return data[data.columns[-1]].values[0]
    #choose best attribute to split. 
    a=best(data)
    #store decision tree in dictionary format with dictionary key being attribute and dictionary value being a list(array) of all 
    #values of the best attribute. The value is further recursively stored as a dictionary with dictionary key being attribute value and
    #dictioniary value being next attribute that is split. i.e. recursively store decision tree as dictionary of values 
    root={a:[]}
    V=data[a].value_counts(normalize=True)
    #print("Attr:",a,"Val:",V)
    for v in V.index:
        #filter data with specific value of attribute
        data_v=data[data[a]==v]
        #delete split attribute as we have already done using it nd dont need it for further splitting. 
        del data_v[a]
        #recursively add child node of the decision tree to the parent node. Here attribute value is the dictionary key and next best 
        #attribute to split is the dictionary value.For one level attribute name is key and for next level attribute value is key and so on.
        root[a].append({v:[dec_tree(data_v,attr.drop(a),data)]})
    #print(root)
    #return subree
    return root   


# In[11]:


#print decision tree
dt=dec_tree(data,data.columns,data)


# In[12]:


dt


# In[13]:


#test data
test={'Occupied':'Moderate','Price':'Cheap','Music':'Loud','Location':'City-Center','VIP':'No','Favorite Beer':'No'}
temp=dt
#travel the decision tree and when leaf is reached break the loop. Leaf is stored as a list and not as dictionary. 
while(type(temp)==dict):
    for vv in temp.values():
        for v in vv:
            if(list(v.keys())[0]==test[list(temp.keys())[0]]):
                temp=list(v.values())[0][0]
                break
print("Predicted answer:",temp)
        


# In[ ]:





# In[14]:


dt


# In[15]:


data


# In[16]:


from sklearn import tree
clf = tree.DecisionTreeClassifier(criterion='entropy')
data1=data
#test data for which prediction is needed
testing=pd.DataFrame({'Occupied':['Moderate'],'Price':['Cheap'],'Music':['Loud'],'Location':['City-Center'],'VIP':['No'],'Favorite Beer':['No']})


# In[17]:


from sklearn.preprocessing import LabelEncoder
#The library method does not deal with labelled data, instead it onyl works with numerical data. So convert each attribute to
#a unique number. This is what LabelEncoder() function does. 

for c in data1.columns:
    enc1=LabelEncoder()
    #since test data doesnt have label, we omit encoding it when we are encoding label attribute
    if(c!='Enjoy'):
        testing[c]=enc1.fit_transform(testing[c])
    data1[c]=enc1.fit_transform(data1[c])


# In[18]:


data1


# In[19]:


#fit training data attributes and labels.
clf=clf.fit(data1[['Occupied', 'Price', 'Music', 'Location', 'VIP', 'Favorite Beer']],data1['Enjoy'])


# In[20]:


#here 'Yes' is mapped to 1 and 'No' is mapped to 0. so the tree predicted 'Yes' as Output
clf.predict(testing)


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[25]:


from sklearn.tree import _tree

def dtfrom_func(clf, cols):
    dt = clf.tree_
    col=[]
    for f in dt.feature:
        col.append(cols[f])

    def rec(attr, d):
        indent = "  " * d
        if dt.feature[attr] != _tree.TREE_UNDEFINED:
            name = col[attr]
            threshold = dt.threshold[attr]
            print ("if",name," less than or equal to ",threshold," then")
            rec(dt.children_left[attr], d+1)
            print ("else")
            rec(dt.children_right[attr], d+1)
        else:
            print ("Leaf node: ",(dt.value[attr]))

    rec(0, 1)


# In[27]:


#Leaf nodes being number of 'Yes' and 'No' instances.
dtfrom_func(clf,data1.columns)


# In[ ]:





# In[ ]:




