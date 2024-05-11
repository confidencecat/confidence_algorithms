# Euclidean Algorithm(유클리드 알고리즘)

### 설명(증명)
양수 a, b (a > b)에 대해 r = a _mod_ b (0 <= r < b)가 성립 한다면 GCD(a, b) = GCD(b, r)을 성립한다.


r = a _mod_ b가 성립한다면  _a = bq + r_ 이다. (q = a를 b로 나누었을 때의 묷, q는 양의 정수)


_a = kn_  _b = km_  (k = a와 b의 공약수)


즉,  _bq = knq_ ,  _r = a - bq = km - knq = k(m-nq)_ 이다.


이를 통해서 k는 r의 약수라는 것을 알 수 있다. 그러므로 정수 k는 a, b, aq, r의 공약수로 a, b의 공약수 집합과 b, r의 공약수 집합은 같은 집합이다.
GCD(a, b) = GCD(b, r)

유클리드 알고리즘은 r이 0이 되었을 때 b의 값이 최소공배수임을 이용한 알고리즘이다.
