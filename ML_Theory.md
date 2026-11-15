# Group B: Machine Learning Theory and Algorithms

## B1. Uber fare prediction

### Theory

Linear Regression predicts a continuous value using a straight-line
relationship between input and output. Random Forest uses many decision trees
and combines their predictions. Both models are used here to predict the
Uber fare.

### Algorithm

1. Read the Uber dataset.
2. Remove unnecessary columns and missing values.
3. Extract the pickup hour.
4. Calculate the distance between pickup and drop locations.
5. Remove invalid values and outliers.
6. Split the data into training and testing data.
7. Train a Linear Regression model.
8. Train a Random Forest Regression model.
9. Predict the fare using both models.
10. Compare the models using R2 score and RMSE.

## B2. Spam classification using KNN and SVM

### Theory

K-Nearest Neighbors classifies a message by checking the classes of its
nearest data points. Support Vector Machine finds a boundary that separates
different classes. Here, both methods classify emails as spam or not spam.

### Algorithm

1. Read the email dataset.
2. Separate the email features and prediction column.
3. Split the data into training and testing data.
4. Scale the feature values.
5. Train a KNN classifier.
6. Train an SVM classifier.
7. Predict the class of test emails.
8. Compare the accuracy and confusion matrix of both models.

## B3. Customer churn prediction using neural network

### Theory

A neural network contains input, hidden, and output layers. It learns patterns
from the training data by changing its weights. In this problem, the network
predicts whether a customer will leave the company.

### Algorithm

1. Read the customer churn dataset.
2. Remove unnecessary columns.
3. Convert text columns into numerical values.
4. Separate the input features and target column.
5. Split the data into training and testing data.
6. Scale the feature values.
7. Create a neural network with hidden layers.
8. Compile and train the network.
9. Predict churn for the test data.
10. Print the accuracy and confusion matrix.

## B4. Diabetes prediction using KNN

### Theory

KNN classifies a new record by checking the nearest records in the training
data. The majority class among these records becomes the prediction. Here, it
predicts whether a person has diabetes.

### Algorithm

1. Read the diabetes dataset.
2. Separate the input features and outcome column.
3. Split the data into training and testing data.
4. Scale the feature values.
5. Create a KNN classifier.
6. Train the classifier.
7. Predict the outcome for test data.
8. Print the confusion matrix, accuracy, error rate, precision, and recall.

## B5. Sales clustering using K-Means

### Theory

K-Means is an unsupervised learning algorithm. It divides data into groups
called clusters. Each record is assigned to the nearest cluster center. The
elbow method helps select a suitable number of clusters.

### Algorithm

1. Read the sales dataset.
2. Select the numerical sales features.
3. Scale the feature values.
4. Run K-Means for different values of `k`.
5. Store the WCSS value for every `k`.
6. Draw the elbow graph.
7. Select the suitable number of clusters.
8. Apply K-Means with three clusters.
9. Add the cluster number to the dataset.
10. Display the records and cluster counts.
