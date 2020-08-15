Q1:
There are only  totally 11 independent variables , the input attributes and 1 dependent variable , the output,MEDV and 1 Bias term .

So total is 12 TERMS.(11 attributes and 1 bias.)(If output variable MEDV is also considered as a term, then it is 13), with 2 attributes INDUS and AGE being omitted.
This means that a small change in these two variables do not contribute SIGNIFICANTLY in determing the median home price.
The values are theoretically assigned some coefficient, but since WEKA doesnt show coefficients below 4 decimal places, it means that the coefficient is <0.0001 so the contribution of these 2 variables on the median price(on changing small/unit value of these varialbes) are small and PRACTICALLY negligible.

(Actually Weka defaultly uses M5 attributeSelectionMethod. If it is changed ot none, then we get a coefficient for all inputs. The attribute selector method selects the attribute that best predicts the output.)


It also shows that people do not fix house prices based on small changes in the proportion of non-retail business in the town and the proportion of owner-occupied units built before 1940.
(like if the ages of two houses is 40 and 50 and other inputs are the same, then the price of both the houses should be very close to each otherupto 4 decimal places)
For the rest of inputs, a small/unit change contributes some change in the median house price.


Other variables like CRIM(per capita crime rate by town),NOX(nitric oxides concentration),DIS(weighted distances to five Boston employment centres),TAX(full-value property-tax rate per $10,000),PTRATIN(pupil-teacher ratio by town) and LSTAT(% lower status of the population) have negative coefficients because these are the factors that people wont prefer i.e. people prefer lesser values for these attributes ie. lesser the value of these attributes, more the proce. So there is a negative correlation,an inverse relationship, between the attributes and the median home price. People prefer lower crime rate, lower taxes, lower pollution, lower pupil-student ratio i.e. more teachers per pupil and lower concentration of poor people.

Other attributes like ZN,CHAS,RM,RAD,B have positive coefficient because there is a direct relationship,positive correlation, between them and the median price because people prefer more residential area, closer to river,more rooms,easy accessibility to highways and people are okay to live amongst black people(not racists).

Q2:
LOWEST RMSE:3.34 with learning rate=0.1,momentum=0.1,no of iterations=500, hidden layer size=12
With learning rate constant and momentum being reduced gradually from 0.3 to 0.1, the RMSE erroe decreased
With momentum fixed and learning rate reduced gradually from 0.3 to 0.1, RMSE decreased. 
So the ideal minima,following the trend, would be when learning rate=0.1 and momentum=0.1
Also whne hidden layer size was changed form 1 to 25, it had a local minima at hidden layer size=7 another local minima at size=12, with the latter giving lesser RMSE. Increasing number of iterations gave more RMSE and decreasing number of iteraitons also gave more RMSE. So the default no. of iterations=500 was the best.

Q3:

Num of rings=-0.8249*(sex=I) + 0.0577*(sex=M) + -0.4583*(length) + 11.0751*(diameter) + 10.7615*(height) + 8.9754*(whole_weight) + -19.7869*(shucked_weight) + -10.5818*(viscera_weight) + 8.7418*(shell_weight) + 3.8946

Here sex=I and sex=M are considered as separate binary attributes because Sex is a categorical nominal attribute which takes 3 values 'M','F','I' .When sex='F', both attributes are set to 0 hence there is no separate sex='F' attribute. It can be seen that number of rings is inversly proportional to 'shucked weight' and sex='I', but directly proportional to all other attributes.

Q4:

NOTE: I manually expanded the nodes to get the FULL tree.
I have submitted two versions of the FULL decision tree.One is manually expanded version and other is using 
Decision tree to Image node and Image Writer(port). The latter also gives the actual FULL tree and so I have also submitted it with the names 'alt' .
 
Decision tree is large because the value of "min number of records per node" is set to 2 and no pruning is done.

NOTE:
For Q5,Q6 many screenshots of results have been included.

Q5:
NOTE:IGNORE ADDITIONAL SUBMISSIONS 
Cluster Model(number of points in each cluster)
Cluster 0: 1388 items(points)
Cluster 1: 499 items(points)
Cluster 2: 448 items(points)
Cluster 3: 22 items(points)
Cluster 4: 172 items(points)
Cluster 5: 1648 items(points)
Total number of items: 4177(points)

Most of the points are centered around Cluster 5 and cluster 0.

Q6: Equation

num_rings= -11.933*length + 25.766*diameter + 20.358*height + 2.836

the number of rings in inversly proportional to length and directoly proportional to diameter and height attributes.