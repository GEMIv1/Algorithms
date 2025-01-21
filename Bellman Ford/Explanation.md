<h2>What is Bellman-Ford algorighm?</h2>
<p>

Bellman-Ford calculates the minimum distance from a starting node to all other nodes in the graph, even in the presence of negative weight edges. Unlike Dijkstra, it can detect negative weight cycles. However, it does not compute meaningful shortest paths if a negative weight cycle exists.

</p>

<h2>How to implement it with dp?</h2>
<h3>Step 1: Initialization</h3>
<p>

- Create a table called dp, and Initialize it with infinity because we did not iterate over the edges yet, so we did not visit any node except the staring node.
- dp[0][start] = 0, because it is the start point that we did not move.

</p>

<h3>Step 2: Filling the table</h3>
<p>

- We iterate for k(At most edges) till n-1, because the node can has at most n-1 edges.
- The first loop is used to carry forward the lowest cost calculated so far. For example, if we reached node A using two edges, and this is the only way to reach it we must propagate its value to subsequent states like dp[3][A], dp[4][A], and do on. Failing to do so would result in dp[3->n][A] being infinity, which is incorrect because we have already reached A with minimum cost using 2 edges.

- The second loop used for the relaxation and minimizing the values.
</p>


<h3>Step 3: Checking for negative cycles</h3>
<p>

- After calculating the minimum values for all nodes, we loop for all edges once more and see if we can relax it one more time 
(dp[n-1][edge.from] + edge.weight < dp[n-1][edge.to]). Why dp[n-1]? because we calculated all best values for all nodes n-1 time in the loops above so if we add another value and it getting smaller, then there is a negative cycle.

</p>

<h2>Time complexity: <em><strong> O(mn) </em></strong> </h2>
