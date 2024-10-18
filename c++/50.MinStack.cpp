/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time. Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty
stacks. At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/

// Pseudo Code
/*
class Solution {
  stack<pair<int, int>> st;

  void push(int val) {
    if (st.empty()) {
      st.push({val, val})
    } else {
      st.push({val, min(val, st.top().second)});
    }
    getMin() { st.top().second; }
  }
  void pop() {
    if (st.empty())
      return;

    n = st.top();
    st.pop();

    if (n < min) // modified value
      min = 2 * min - n
  }

  int top() { st.top().first; }
  int getMin() { return min; }
};
*/
// Time Complexity: O(1)
// Space Complexity:O(2*N)
/*
    2 *val -prev_min = newVal
prevMini = 2 *val -newVal

val -mini <0
val + val - min < val
2val - min<val =>
newVal <val
*/

// PseudoCode
/*
class MinStack{
stack<int> st;
push(val){
if(st.empty())
    min=val
    st.push(val)
else
    if(val>min) st.push(val)
    else{
        st.push(2*val-min)
        min=val;
        }
}

pop(){
if(st.empty())
    return;

n=st.top();
st.pop();

if(n<min)   //modified value
    min=2*min-n
}

top(){
if(st.empty())
    n=st.top();
if(min<n)
    return n;

return min;
}

getMin(){
return min;
}
}
*/

// Time: O(1)
// Space:O(n)
//
#include <climits> // for INT_MAX
#include <stack>

class MinStack {
private:
  std::stack<long long> st;
  long long min =
      INT_MAX; // Initialize min with the maximum possible integer value

public:
  void push(int val) {
    if (st.empty()) {
      min = val;
      st.push(val);
    } else {
      if (val >= min) {
        st.push(val);
      } else {
        st.push(2 * val - min);
        min = val;
      }
    }
  }

  void pop() {
    if (st.empty())
      return;

    int n = st.top();
    st.pop();

    if (n < min) {
      min = 2 * min - n;
    }
  }

  int top() {
    if (st.empty())
      return -1; // or throw an exception

    int n = st.top();
    if (n < min)
      return min;
    else
      return n;
  }

  int getMin() { return min; }
};
