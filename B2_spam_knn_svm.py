import pandas as pd

from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score

# Load dataset
df = pd.read_csv("spam.csv", encoding="latin-1")

# Select columns
df = df[["v1", "v2"]]
df.columns = ["label", "message"]

# Convert labels into numbers
df["label"] = df["label"].map({
    "ham": 0,
    "spam": 1
})

# Separate input and output
X = df["message"]
y = df["label"]

# Convert text into numerical data
vectorizer = TfidfVectorizer(stop_words="english")
X = vectorizer.fit_transform(X)

# Split dataset
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# KNN Classifier
knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, y_train)

pred1 = knn.predict(X_test)

# SVM Classifier
svm = SVC(kernel="linear")
svm.fit(X_train, y_train)

pred2 = svm.predict(X_test)

# Compare accuracy
print("KNN Accuracy:", accuracy_score(y_test, pred1))
print("SVM Accuracy:", accuracy_score(y_test, pred2))