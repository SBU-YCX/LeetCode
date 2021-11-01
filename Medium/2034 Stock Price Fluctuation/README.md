# [2034. Stock Price Fluctuation](https://leetcode.com/problems/stock-price-fluctuation/)


## Description:

<p>You are given a stream of <strong>records</strong> about a particular stock. Each record contains a <strong>timestamp</strong> and the corresponding <strong>price</strong> of the stock at that timestamp.</p>
<p>Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect. Another record with the same timestamp may appear later in the stream <strong>correcting the price of the previous wrong record.</p>
<p>Design an algorithm that:</p>
<ul>
  <li><strong>Updates</strong> the price of the stock at a particular timestamp, <strong>correcting</strong> the price from any previous records at the timestamp.</li>
  <li>Finds the <strong>latest price</strong> of the stock based on the current records. The <strong>latest price</strong> is the price at the latest timestamp recorded.</li>
  <li>Finds the <strong>maximum price</strong> the stock has been based on the current records.</li>
  <li>Finds the <strong>minimum price</strong> the stock has been based on the current records.</li>
</ul>
<p>Implement the <code>StockPrice</code> class:</p>
<ul>
  <li><code>StockPrice()</code> Initializes the object with no price records.</li>
  <li><code>void update(int timestamp, int price)</code> Updates the <code>price</code> of the stock at the given <code>timestamp</code>.</li>
  <li><code>int current()</code> Returns the <strong>latest price</strong> of the stock.</li>
  <li><code>int maximum()</code> Returns the <strong>maximum price</strong> of the stock.</li>
  <li><code>int minimum()</code> Returns the <strong>minimum price</strong> of the stock.</li>
</ul>


## Examples:

<strong>Example 1:</strong>
<pre>
<strong>Input:</strong>
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
<strong>Output:</strong> 
[null, null, null, 5, 10, null, 5, null, 2]
<strong>Explanation:</strong> 
StockPrice stockPrice = new StockPrice();
stockPrice.update(1, 10); // Timestamps are [1] with corresponding prices [10].
stockPrice.update(2, 5);  // Timestamps are [1,2] with corresponding prices [10,5].
stockPrice.current();     // return 5, the latest timestamp is 2 with the price being 5.
stockPrice.maximum();     // return 10, the maximum price is 10 at timestamp 1.
stockPrice.update(1, 3);  // The previous timestamp 1 had the wrong price, so it is updated to 3.
                          // Timestamps are [1,2] with corresponding prices [3,5].
stockPrice.maximum();     // return 5, the maximum price is 5 after the correction.
stockPrice.update(4, 2);  // Timestamps are [1,2,4] with corresponding prices [3,5,2].
stockPrice.minimum();     // return 2, the minimum price is 2 at timestamp 4.
</pre>


## Constraints:

<ul>
  <li><code>1 &lt;= timestamp, price &lt;= 10<sup>9</sup></code></li>
  <li>At most <code>10<sup>5</sup></code> calls will be made in total to <code>update</code>, <code>current</code>, <code>maximum</code>, and <code>minimum</code>.</li>
  <li><code>current</code>, <code>maximum</code>, and <code>minimum</code> will be called <strong>only after</strong> <code>update</code> has been called <strong>at least once</strong>.</li>
</ul>


## Solution:

<strong>Logical Thinking</strong>
<p>Use a <strong>hash table</strong> to keep a record of the pair of <code>{timestamp, price}</code>, then we can easily complete <code>update</code> and <code>current</code> operations. Since the elements in the hash table is sorted by <code>timestamp</code>, we need another sorted data structure for <code>price</code> to complete <code>maximum</code> and <code>minimum</code>, which should also allow duplicate values, then we choose a <strong>multiset</strong>, because the operation <code>update</code> needs to erase the old values and multiset allows to only erase one value when there are multiple equal values.</p>

 
<strong>C++</strong>

```
//  Topic   ：2034. Stock Price Fluctuation (https://leetcode.com/problems/stock-price-fluctuation/)
//  Author  : YCX
//  Time    : O(logN) [for each operation]
//  Space   : O(N)


class StockPrice {
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (m.find(timestamp) != m.end())
        {
            int old = m[timestamp];
            s.erase(s.lower_bound(old));
        }
        m[timestamp] = price;
        s.insert(price);
    }
    
    int current() {
        return (*m.begin()).second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
    
private: 
    map<int, int, greater<int>> m;
    multiset<int> s;
};
```
