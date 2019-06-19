# Heur-GED
An efficient heuristic estimation for graph edit distance computaiton 

## What is it?
Heur-GED is an anytime algorithm for graph edit distance (GED) computation. It employs 
the expanded branch edit distance as the heuristic estimation in the tree-based algorithm for the 
GED computation. Adopting the anytime algorithm framework, Heur-GED can fast seek an initial suboptimal solution 
of GED and then output a sequence of imporved solutions when reaching the maximum running time. 

## How to use it?   
### Step I. Install
   1. download (or clone) the source code from https://github.com/Hongweihuo-Lab/NBA-GED/
   2. Compile the source code. 
### Step II. run NBA-GED
   1. run the shell command: "./NBAGED profile path cc beta time", where    
       (1) profile is the config file that contains the compared graph paris.       
       (2) path is the position in which the data is located.        
       (3) cc is the cost function, e.g., cc = 0 is the GREC cost fucntion, cc = 1 is the MUTA cost function. These 
           cost functions were taken from the repository[1].            
       (4) beta is the attenuation factor.       
       (5) time is the available running time. 
       
## Contributors
### code
•	Xiaoyang Chen 
### paper
NBA-GED is an implementation of the paper.

X. Chen, H. Huo, et al. An Improved Anytime Algorithm for Approximate Graph Edit Distance Computation, submitted. 
## Reference
[1]. Z. Abu-Aisheh, R. Raveaux, and J. Y. Ramel. A graph database repository and performance evaluation metrics for graph edit distance. In GbPRP, pages 138–147, 2015.

## Data Format

### format of the graph data 
this program reads graph data in a specific format, thus please strictly 
follow the formatting rules in the sample file as provided.

E.g., ...

      pdb1nj5                           //graph name 
      40 95                             //vertex and edge sizes 
      0 SHMQKPIKKDPNR + +               //the vertex property: type, AA-seq., x, and y 
      ...
      1 SFMWCGE + +     
      0 1 1                            //from, to, #attirbutes
      1 34.14298                       //type, and distance 
      ...
      14 39 1
      4 1.0
      39 44 
      ...
 
[Feedback]
Report bugs to <jackcxy@126.com>. Your feedback and test results are welcome.
