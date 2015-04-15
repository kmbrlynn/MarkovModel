ps6-readme.txt
Kim Douglas

// ================================== constructor

For my implementation, I did a lot of work in the constructor. 
First, I parsed the alphabet out of the string of text, and 
saved it in a member variable.

Then I built all the k-grams and all the k-plus-one grams
in one big loop that corresponded to the length of the text. 

(I ended up having to do some wonky things with the loop indices, 
like starting at one, and ending at one past the length, 
because of the way I handled wrapping k-grams around. I basically
did some arithmetic to get the chunk of text on the end and
the chunk of text at the beginning, and concatenate them. If
I didn't begin my loop index at one, I would've ended up with
a negative index when I got my wraparound index. In the future, 
I won't make this so convoluted.)

Still in this loop in the constructor, I put all the kgrams 
and kplus grams in the map.

// ==================================== frequencies

My freq() functions are pretty straightforward - iterate through
the map to find them, and if it doesn't find them, it returns 
zero. The freq() function that takes a character
keeps a tally of the frequency if the order is zero, and then 
returns that. 

// ======================================== randk

My randk iterates through each unique letter in the 
alphabet member variable. It takes the alpha character
at the current index and passes it to the freq(string, char)
function, to return the number of times the letter is 
found after the kgram. I could have done some arithmetic
here, but I didn't. Instead, this tally is used as an exit 
condition for a loop that pushes that many of the characters to a 
vector. After this is repeated for all characters, 
a vector with their correct probabilities is created, and
a character at a random index is returned. Next time I probably
wouldn't do it this way, since it's inefficiently N^2

// =========================================== gen

My generate function starts with a string that is set
to the value of the passed kgram. Then it takes what the
probable next character is, using the rand(kgram) function.
This character gets appended to the string that will be returned.
The kgram is then reset for the next loop iteration: with a 
dropped first character and an appended probablistic 
character. At the loop's exit - determined by a user-specified
length t - the generated string is returned

// =============================== GenerateText client

I made a usage exception. The client also prints the
entire map and the alphabet. I had to seed the random
number generator to call the gen() function, after which
I print the input string and the generated string. 









