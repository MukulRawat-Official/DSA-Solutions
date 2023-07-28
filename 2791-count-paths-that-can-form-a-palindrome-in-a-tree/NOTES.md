-> we create mask of  [a - z] freaquency till all root.
-> now we store all mask (cool trick)
even no :-  no of elements mask is same (why it work ?)
​
because :-
1.> for same subtree above mask(parent) will be same (only sub mask will be checked)
2.> for two different branch we can say same thing.
​
odd no :- let this odd character be [a - z]
for each mask  try to put this character
and add this answer.
like   mask1 ^ ch = mask2  eg :- (a ^ b =  ab  ||  a = ab ^ b)
answer will be added two time so  divide / 2;
in odd case a condition also occur where there is only one character odd
eg : aba , a , abbca    in this   total xor will be zero
so we need to add extra zero mask in beginning.