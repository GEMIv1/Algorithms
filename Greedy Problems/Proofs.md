## 1) Customer Scheduling:
### Proof: Sorting Service Times in Increasing Order Minimizes Total Waiting Time

Let us assume there are `n` customers, where each customer \( a_i \) has a service time $ t_i $. The total waiting time for all customers is the sum of their individual waiting times, which depends on the order in which customers are served. We aim to prove that sorting the service times in increasing order minimizes the total waiting time.

### Argument:
- Suppose the service times $t_1, t_2, \dots, t_n $ are **not** sorted in increasing order.
- Let there exist two customers $ a_i $ and $ a_{i+1} $ such that $ t_i > t_{i+1} $. This implies that the service times are out of order.
- In this arrangement:
  - Customer $ a_{i+1} $ must wait for $ t_i $ to complete their service.
  - Similarly, if there exists $ a_{i+2} $ such that $ t_{i+1} > t_{i+2} $, then $ a_{i+2} $ will wait for $ t_i + t_{i+1} $, which results in a longer waiting time.

- **Reordering:** If we swap $ a_i $ and $ a_{i+1} $ such that $ t_{i+1} < t_i $, then:
  - The waiting time for $ a_{i+2} $, $ a_{i+1} $, and subsequent customers will decrease.
  - Although the waiting time for $ a_i $ increases, the **increase in waiting time for $ a_i $** is smaller than the **decrease in waiting time for $ a_{i+1} $ and subsequent customers**.

### Conclusion:
By applying this reordering iteratively for every pair $ t_i, t_{i+1} $ where $ t_i > t_{i+1} $, we eventually achieve an arrangement where the service times are sorted in increasing order. This minimizes the total waiting time for all customers, as it reduces the cumulative sum of waiting times.

Thus, sorting the service times in increasing order indeed minimizes the total waiting time.


## 2) Interval Scheduling:
### Proof: Sorting intervals by the end Times in Increasing Order Increase the number of Intervals can be taken


- If two intervals overlap, we will take the interval with the earliest end so we can take more intervals.

- By taking the earliest end, the algorithm ensures that the remaining time is maximized for future intervals.
