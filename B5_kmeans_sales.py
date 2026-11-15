import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

# Read the sales data.
data = pd.read_csv("sales_data_sample.csv", encoding="latin1")

# Select the columns used for clustering.
features = data[["SALES", "QUANTITYORDERED", "PRICEEACH", "MSRP"]].dropna()

# Scale the values.
scaled_features = StandardScaler().fit_transform(features)

# Find the best number of clusters using the elbow method.
wcss = []
for k in range(1, 11):
    model = KMeans(n_clusters=k, random_state=42, n_init=10)
    model.fit(scaled_features)
    wcss.append(model.inertia_)

plt.plot(range(1, 11), wcss, marker="o")
plt.xlabel("Number of clusters")
plt.ylabel("WCSS")
plt.title("Elbow Method")
plt.show()

# Create three clusters.
model = KMeans(n_clusters=3, random_state=42, n_init=10)
data = data.loc[features.index].copy()
data["Cluster"] = model.fit_predict(scaled_features)

print(data[["SALES", "QUANTITYORDERED", "Cluster"]].head(10))
print("\nCluster counts:")
print(data["Cluster"].value_counts())
