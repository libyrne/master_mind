# Master Mind

Task division:
- Lisa: Make header file
- Kaite: Make main()
- Alek: Make Check functions


Psuedo:
For CheckIncorrect function:
- two embedded for loops (outside is to go through secret code vector, inside is to go through the guess vector)
- If statement inside loops to ignore looking at same index (don't want to check for right digit in right place)
- If statement in if statement to check if value is in wrong place
- If value is in wrong place, make the value in the guess m (out of range so it can't be checked twice) 

```
int checkIncorrect(const vector& sc, vector& guess){
for (int sc_i = 0; sc_i < n; sc_i ++){
   for (int g_i = 0; g_i < n; g_i ++){
       if g_i != sc_i{
           if sc[sc_i] == g[g_i]:
                count += 1;
                g[g_i] = m;
                
           }
      }
}
```


Main(): 
- Ask player for length and range 
- Generate secret code 
- Hard code three examples as guest code 
- Print results of checks 
- Print secret code 
