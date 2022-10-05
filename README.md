# Hacktober-Fest-2022
Add your program files here I will accept it. Happy Coding!

Problem Description : Return True for the word only if you are able to find an index & by removing that particular index your frequency of word becoming equal and false otherwise.

Why this approach(Not the damn problem) is easy...??

As here i am not focusing on where the case will be false instead am returning the case when the condition can only become true.

hence it's easy to understand...

What we need to do here is... just check whether you are able to make frequency in corresponding char as 1 or not . for this you can take help of set. Now iterate in a for a loop and check this condition if yes return true and false otherwise.

for eg.,

word = mmkkkrrtt

now as we can see each word is having frequency 2 except k which is having freq 3 and we need to find 1 index for which we can make freq equal for all other char by removing it.

Nice, now dry run on this example:

for loop will run till length of 9:

then for each char from starting char till that char and from next char to end of the word we will find its frequency and store them in a set (Why Set...) and check whether frequency is one or not. If for any index it is coming 1 means we can have such index and we will return True.

Why Set... As we are looking on frequency of each char from starting to that index and after that index to end hence all the char will have some frequency and in a set we will focus on unique frequency basically set will contain frequency of each char so here it will look like this [1,2,3] at index other than 3,4 and 4,5. It will look like [2] at index 3,4 and 4,5 but when we take length it will give 3 (for index other than 3,4 and 4,5) and finally we compare it with 1.

So,

for starting from i=0 to i=9 you will get

x=len(set(Counter(word[:0] + word[1:]).values())) will give 3
x=len(set(Counter(word[:1] + word[2:]).values())) will give 3
x=len(set(Counter(word[:2] + word[3:]).values())) will give 3
x=len(set(Counter(word[:3] + word[4:]).values())) will give 1
x=len(set(Counter(word[:4] + word[5:]).values())) will give 1
x=len(set(Counter(word[:5] + word[6:]).values())) will give 3
x=len(set(Counter(word[:6] + word[7:]).values())) will give 3
x=len(set(Counter(word[:7] + word[8:]).values())) will give 3
x=len(set(Counter(word[:8] + word[9:]).values())) will give 3

Hence, here it will give True for an index as we are getting length of set 1 by removing that index and we are getting all other char freq as equal to 2.

Also we are getting 1 twice as freq of each char is 2 means we can remove 1 index from 2 char and same is happening here. either index 3,4 or 4,5. But its not a concern for us as we will return True as soon as we will get 1.
