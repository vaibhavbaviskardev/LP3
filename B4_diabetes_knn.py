import sys

import pandas as pd
from sklearn.metrics import (
    accuracy_score,
    confusion_matrix,
    precision_score,
    recall_score,
)
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler


df = pd.read_csv("diabetes.csv")
df.head()

features = df.drop("Outcome", axis=1)
target = df["Outcome"]

features_train, features_test, target_train, target_test = train_test_split(
    features, target, test_size=0.2, random_state=42
)
scaler = StandardScaler()
features_train = scaler.fit_transform(features_train)
features_test = scaler.transform(features_test)

knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(features_train, target_train)
predictions = knn.predict(features_test)

accuracy = accuracy_score(target_test, predictions)
print("Confusion matrix:\n", confusion_matrix(target_test, predictions))
print("Accuracy  :", accuracy)
print("Error rate:", 1 - accuracy)
print("Precision :", precision_score(target_test, predictions))
print("Recall    :", recall_score(target_test, predictions))
