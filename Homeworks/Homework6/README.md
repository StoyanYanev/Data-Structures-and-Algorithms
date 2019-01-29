**Задача 1.(HeightOfABinaryTree)**

The height of a binary tree is the number of edges between the tree&#39;s root and its furthest leaf. For example, the following binary tree is of height :

![Image 1](Homeworks/Homework6/1.png)

Complete the _getHeight_ or _height_ function in the editor. It must return the height of a binary tree as an integer.

getHeight or height has the following parameter(s):

- _root_: a reference to the root of a binary tree.

**Note**  -The Height of binary tree with single node is taken as zero.

**Input Format**

The first line contains an integer , the number of nodes in the tree.
Next line contains  space separated integer where th integer denotes node[i].data.

**Note** : Node values are inserted into a binary search tree before a reference to the tree&#39;s root node is passed to your function. In a binary search tree, all nodes on the left branch of a node are less than the node value. All values on the right branch are greater than the node value.

**Constraints**

**Output Format**

Your function should return a single integer denoting the height of the binary tree.

**Sample Input**

 ![Image 2](/2.png)

**Sample Output**

3

**Explanation**

The longest root-to-leaf path is shown below:

![Image 3](/3.png)

There are  nodes in this path that are connected by  edges, meaning our binary tree&#39;s .

**Задача 2.(TopView)**

You are given a pointer to the root of a binary tree. Print the top view of the binary tree.
Top view means when you look the tree from the top the nodes, what you will see will be called the top view of the tree. See the example below.
You only have to complete the function.

For example :
```
   1

    \

     2

      \

       5

      /  \

     3    6

      \

       4
```
Top View : 1 -> 2 -> 5 -> 6

**Input Format**

You are given a function,

void topView(node \* root) {

}

**Constraints**

1 Nodes in the tree  500

**Output Format**

Print the values on a single line separated by space.

**Sample Input**
```
   1

    \

     2

      \

       5

      /  \

     3    6

      \

       4
```
**Sample Output**

1 2 5 6

**Explanation**
```
   1

    \

     2

      \

       5

      /  \

     3    6

      \

       4
```
From the top only nodes 1,2,5,6 will be visible.
