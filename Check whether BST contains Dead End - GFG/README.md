# Check whether BST contains Dead End
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:20px">Given a&nbsp;<a href="http://quiz.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/" target="_blank">Binary search Tree</a>&nbsp;that contains positive integer values greater then 0. The task is to complete the function <strong>isDeadEnd</strong> which returns true if&nbsp;the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.</span></p>

<p><span style="font-size:20px">Examples:</span></p>

<pre><span style="font-size:20px">Input :   
&nbsp;              8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
&nbsp;             we cant insert any element.       

</span></pre>

<pre><span style="font-size:20px">Input :     
&nbsp;             8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at 
              node 9.  </span></pre>

<p><br>
<span style="font-size:20px"><strong>Input:</strong><br>
The first line of the input contains an integer 'T' denoting&nbsp;the number of test cases. Then 'T' test cases follow. Each test case consists of three&nbsp;lines.&nbsp;First line of each test case contains an integer N denoting the no of nodes of the BST&nbsp;. Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.<br>
<br>
<strong>Output:</strong><br>
The output for each test case will be 1 if the BST contains a dead end else 0.</span><br>
&nbsp;</p>

<p><span style="font-size:20px"><strong>Constraints:</strong><br>
1&lt;=T&lt;=100<br>
1&lt;=N&lt;=200</span><br>
&nbsp;</p>

<p><span style="font-size:20px"><strong>Example(To be used only for expected output):</strong><br>
<strong>Input:</strong><br>
2<br>
6<br>
8 5 9 7 2 1<br>
6<br>
8 7 10 9 13 2<br>
<strong>Output:</strong><br>
1<br>
1</span></p>
 <p></p>
            </div>