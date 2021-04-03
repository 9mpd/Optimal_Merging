# Optimal_Merging
Optimal merging of different data sets or files.

### Optimal merge pattern using greedy approach.

Optimal merge pattern is a greedy method to merge two or more files in the minimum possible time. \
To achieve our objective, we start with the two smallest files. \
In the next step, we merge the next two smallest files, \
including the file that we merged in the previous step.\
And, do the same till we get the only one file. 

For e.g. suppose we have four files **f<sub>1</sub>, f<sub>2</sub>, f<sub>3</sub> & f<sub>4</sub>** with sizes **5, 7, 3 & 8** respectively.\
Step 1 : Merge **f<sub>3</sub>** (size = 3) & **f<sub>1</sub>** (size = 5), we get **f<sub>31</sub>** (size = 8).\
Step 2 : Merge **f<sub>2</sub>** (size = 7) & **f<sub>4</sub>** (size = 8), we get **f<sub>24</sub>** (size = 15).\
Step 3 : Merge **f<sub>31</sub>** (size = 8) & **f<sub>24</sub>** (size = 15), we get **f<sub>3124</sub>** (size = 23).

**Here's a diagramatic expalanatiion :**
![image](https://user-images.githubusercontent.com/58243776/113467721-8096bb80-9462-11eb-9c8e-128d1169a91b.png)

