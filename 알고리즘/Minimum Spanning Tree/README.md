# Minimum Spanning Tree(최소 신장 트리)

### 설명


최소 신장 트리(최소 스패닝 트리)는 주어진 그래프의 모든 노드들을 연결하는 부분 그래프 중 그 가중치의 합이 최소인 트리이다.


사이클이 존재하면 가중치의 합이 최소가 될 수 없다. 그렇기 때문에 사이클을 포함해서는 안된다.


N개의 노드가 있다면, 최소 신장 트리를 구성하는 간선 수는 N-1개이다.


사이클의 유무는 union & find를 사용한다.


데이터를 노드가 아닌 간선을 중심으로 저장한다. 즉 인접 리스트가 아닌 간선 리스트 형태로 저장하고, 간선 리스트를 오름차순으로 정렬한다.


가중치가 낮은 간선부터 연결을 한다. 연결을 하기 전에 간선을 연결했을 때 사이클이 존재하는 지 확인해야한다.


find(첫 번째 노드) != find(두 번재 노드)가 성립하면 union(첫 번째 노드, 두 번째 노드)를 하고 최소 신장트리에 가중치를 더한다.


위의 과정을 연결한 간선의 수가 N-1개가 될 때까지 반복한다. 
