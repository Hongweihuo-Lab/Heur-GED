# Heur-GED
An efficient heuristic estimation for graph edit distance computaiton 

## What is it?
Heur-GED is an anytime algorithm for graph edit distance (GED) computation. It employs 
the expanded branch edit distance (BED+) as the heuristic estimation in the tree-based algorithm for the 
GED computation. Adopting the anytime algorithm framework, Heur-GED can fast seek an initial suboptimal solution 
of GED and then output a sequence of improved solutions until reaching the maximum running time. 

## How to use it?   
### Step I. Install
   1. download (or clone) the source code from https://github.com/Hongweihuo-Lab/Heur-GED/
   2. Compile the source code. 
### Step II. run NBA-GED
   1. run the shell command: "./path profile cc LB run_time", where    
       (1) *path* is the position in which the data is located.       
       (2) *profile* is the configure file that contains the compared graph paris.      
       (3) *cc* is the parameter for cost function, such that 
           
            i)   cc = 0 is the GREC cost function;
            ii)  cc = 1 is the MUTA cost function;
            iii) cc = 2 is the PRO cost function;
            iv)  cc = 3 is the CMU cost function;
            v)   cc = 4 is the SYN cost function.           
         The cost functions above were taken from the repository[1].            
       (4) *LB* is the heuristic estimation used in the tree-based search algorithm, such that 
            
            i)   LB = 0 is the label edit distance (LED);
            ii)  LB = 1 is the hausdorff edit distance (HED);
            iii) LB = 2 is the branch edit distance (BED);
            iv)  LB = 3 is the expanded branch edit distance (BED+).        
       (5) *run_time* is the available running time. 
       
## Contributors
### code
•	Xiaoyang Chen 
### paper
Heur-GED is an implementation of the paper.

X. Chen, H. Huo, et al. An efficient heuristic estimation for graph edit distance computaiton, submitted to PRL. 
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
