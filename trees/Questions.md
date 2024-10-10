- Daily Challenge 14 April
![[Pasted image 20240415135415.png]]
![[Pasted image 20240415135511.png]]
As I was a noob and didn't practice linked lists earlier, I couldn't use those simple techniques in trees. But since I did a bunch of LL questions, this question felt pretty easy to me. I checked for 2 conditions, one was to make sure that the node is a leaf node, and the other was I only sum up the left ones. In order to do so, I summed the left node of the current root node(root->left != NULL), and checked for the leaf condition(root->left->left == NULL && root->left->right == NULL).

- Daily Challenge 15 April
![[Pasted image 20240415140242.png]]
![[Pasted image 20240415140454.png]]
![[Pasted image 20240415140527.png]]
The problem statement was pretty clear. There was just a bit of formulae involved and the right placing of that formulae(i.e. adding and removing of digits to form the correct sequence of the number). The removal of the digits as we go back up the tree was important. If I remove the "digit = digit/10" and "return" from the if function, and just keep the digit /= 10, the code still works.

- Daily Challenge 16 April
![[Pasted image 20240416232428.png]]
![[Pasted image 20240416232449.png]]
![[Pasted image 20240416232519.png]]
![[Pasted image 20240416232550.png]]
Took me a while to solve this one and messed on some edge cases but got there eventually. The part I really was messing up was where to increment "currDepth" and where to decrement it. Another was the edge case where depth was equal to 1, I just put an if-condition for that one.








