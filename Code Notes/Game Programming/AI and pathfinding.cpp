////////////////////////////////////////////////////////////////////////////////////////////////////////
//GAME AI: GAME PLAYING AGENTS
////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
GAME THEORY: Study of choice of strategies by interacting agents
ZERO-SUM GAMES: Payoff for players always adds to zero; one player wins what the other loses
NON ZERO-SUM GAMES: Players payoff relational to how much they win/lose
PERFECT INFORMATION: No element of random chance affecting possible moves that can be done (chess)
IMPERFECT INFORMATION: Element of random chance avaliable (trouble)

------------------------------------------------------------------------------------
GAME STRATEGIES
------------------------------------------------------------------------------------
COOPERATIVE SOLUTION: All players agree to a particular strategy choice
NON-COOPERATIVE SOLUTION: No enforced agreements to choices
DOMINANT STRATEGY: A strategy which provides a higher payoff no matter the choice of the other player
DOMINANT STRATEGY EQUILIBRIUM: All players have a dominant strategy and select it

SOCIAL DILEMMA [Dominant Strategy, Cooperative Solution]
PRISONER'S DILEMMA [Dominant Strategy, Non-Cooperative]
NASH EQUILIBRIUM [Non-Dominant, Non-Cooperative]
    Each player chooses the best strategy in response to the strategies chosen by other players
    There is no choice which will be better no matter what the other player chooses. 
    The player can either risk getting 2 or none, or settle for a guaranteed one no matter the other players choice.
    Eg. Rock/Paper/Scissors

------------------------------------------------------------------------------------
GAME TREES
------------------------------------------------------------------------------------
NORMAL FORM: Outcomes by chart
EXTENSIVE FORM: Outcomes by tree diagram
SEQUENTIAL PROBLEM: Multiple decisions determine the outcome
PLY: One set of player/opponent moves
DEPTH: Number of turns from the root node to a leaf node

BRANCHING FACTOR: Number of choices available at one node
UNIFORM BRANCHING FACTOR: Whole tree has same branching factors; choices aren't diminished as game goes on
                          TicTacToe: Non-uniform as choices diminished as game goes on
                          Rubik's cube: Uniform as choice number stays same


////////////////////////////////////////////////////////////////////////////////////////////////////////
//GAME AI: EMBODIED AGENTS
////////////////////////////////////////////////////////////////////////////////////////////////////////

EMBODIED AGENT: 
  Subsystem of a domain (Agent + Environment = Domain)
  Entity that percieves its environment through sensors and acts upon that environment through actuators

EMBODIED AGENT CONSISTS OF:
 1) Sensors
 2) Actuators/Effectors
 3) Locomotion system
 4) Control systems linking everything together

EMBODIED AGENT INFORMATION CYCLE:
 1) PERCIEVES its environment and itself
 2) REASONS about these perceptions and prior knowledge
 3) ACTS in response to reasons and with purpose

RATIONAL AGENT: selects an action that is expected to maximize its performance given what information it has been given
AUTONOMOUS AGENT: acts in a meaningful manner given its perceptions and reasoning (Perception->Reasoning->Action)

REACTIVE SYSTEM (PROCEDURAL): 
 - Uses no world model or reasoning; does constant action towards stimulus
 - BENEFIT: Fast response to stimuli, smaller computations needed                
 - DISADVANTAGE: No guarantee of reaching goal, can result in cyclic behaviour/failure
 - STATE MACHINES: Encodes how to behave in every situation encountered

DELIBERATIVE SYSTEM (DECLARATIVE): 
 - Uses world model; reasons actions and chooses a meaningful one       
 - BENEFIT: Can avoid fatal failures, intelligent and optimal behaviour
 - DISADVANTAGE: Computational cost, slower, requires knowledge of the world around, difficult to deal with uncertainty
 - PLANNING SYSTEM: allows agents to select actions to achieve its goals from its current state

////////////////////////////////////////////////////////////////////////////////////////////////////////
//REACTIVE SYSTEMS: STATE MACHINES
////////////////////////////////////////////////////////////////////////////////////////////////////////

STATE MACHINES DISADVANTAGES:
 - become bloated with lots of states, difficult to manage/debug
 - states difficult to reuse in different contexts
 - only one state active at one time
 - can cycle between states (eg. Line of sight for enemy cycles in/out)

MAIN DIFFERENCES:
 - State Machine outputs if a transition to a new state occurs (Mealy) or currently in a state (Moore)
 - State Automata outputs if the final state occurs after series of transitions

-----------------------------------------------------------------------------------------------------------
FINITE STATE MACHINE:
-----------------------------------------------------------------------------------------------------------
 - Keeps track of the set of possible states, what is required to transition between them, which state it is in
 - At each iteration (frame) the state machines update function is called to see if any transition is triggered
 - if transition is triggered, transition actions are carried out
 - Function returns symbols for what action is to be carried out in the new state
 - Has no terminal states; can be initialised in any state

MEALY MACHINE: Emit signals upon transition
MOORE MACHINE: Emit symbols in each state

-----------------------------------------------------------------------------------------------------------
FINITE STATE AUTOMATA:
-----------------------------------------------------------------------------------------------------------
 - Consumes a sequence of input signals one at a time
 - Has a unique starting state, one or more accepting states and final state
 - If the sequence of inputs causes transitions that result in the final state, output occurs
 - Game Application: Sequence of keys results in attack occuring

-----------------------------------------------------------------------------------------------------------
IMPLEMENTING STATE MACHINES:
-----------------------------------------------------------------------------------------------------------

POLLLING AGENTS: 
  Continually query the game world to determine input for state transitions
  ADVANTAGE: Only queries game world for information when it is needed
  DISADVANTAGE: Constantly asks “are we there yet”

EVENT-DRIVEN AGENTS: 
  Objects in game broadcast messages which the agent picks up when close enough and filter according to importance of agent
  ADVANTAGE: Responds only to messages it finds important, abstracts agent away from generating information; agent only consumes
  DISADVANTAGE: More overhead, harder to code


/*STATE MACHINE ALGORITHM*/
StateMachine
{
    DeclareState(STATE_WANDER)
    {
        OnEnter()
            Execute(ReadyGun)
            
        OnUpdate()
            Execute(Wander)
            if(SeeEnemy)
                ChangeState(STATE_ATTACK)

        OnEvent(AttackedByEnemy)
            ChangeState(STATE_ATTACK)

        OnExit()
            Execute(StoreGun)
    }

    DeclareState(STATE_ATTACK)
    {...}

}
/*
////////////////////////////////////////////////////////////////////////////////////////////////////////
//DELIBERATIVE SYSTEMS: PLANNING
////////////////////////////////////////////////////////////////////////////////////////////////////////

PLAN: Sequence of actions that moves from initial state to goal state
PROGRESSION PLANNING: Forward search from initial state
REGRESSION PLANNING: Backward search from goal

SITUATIONAL PLANNING (State Space Search)
- Gather series of actions based on the situation player is in to get to the goal
- Includes PathFinding to a goal

PARTIAL PLANNING (Plan Space Search)
- Start with empty/partially empty sequence of actions (plan)
- When executing plan, consider ways of expanding the plan looking through all possible plans in the plan space
- Continue until final plan is complete and solves the problem (goal reached)

CONDITIONAL PLANNING (Probability)
 - Probability is used when not all information is known about environment/other agents


////////////////////////////////////////////////////////////////////////////////////////////////////////
//PATHFINDING
////////////////////////////////////////////////////////////////////////////////////////////////////////

VERTICES: Nodes
EDGES: Connects nodes to each other; have weights
ADJACENT VERTICES: verts connected via an edge
DIRECTED GRAPHS: sets direction for edges, limits adjancency
COST: Amount required to reach node (use positive values only)
HEURISTIC: The best guess on how much a node is worth (never overestimate actual cost of node)
POLICY: Solution that tells the optimal/shortest path to any goal node from any start node

DIJKSTRA[UNINFORMED SEARCH METHOD]:
  USED: To search graphs for shortest path
  ACTION: Chooses nodes with lowest cost so far value
  DISADVANTAGE: Searches entire graph considering high amount of nodes; wasteful

A*[INFORMED SEARCH METHOD]:
  USED: Search weighted graphs with heuristics for shortest path
  ACTION: Chooses node with lowest estimated total cost
  ADVANTAGE: Less nodes considered than Dijkstra; effecient
  NOTE: Most ideal to use priority queue with iteration for Open/Closed lists
        std::priority_queue has no iteration; best to use sorted vector

/*ASTAR/DIJKSTRA PATHFINDING ALGORITHMS*/
struct EDGE
{
    Node Parent
    Node Child
    EdgeCost
}
struct NODESTRUCT
{
    Node //use coordinates for ID
    EDGE edgeToParent
    CostSoFar //A* AND DJ
    EstimatedTotalCost  //A* ONLY
}

CREATE_HEURISTIC(Goal,Start) //A* ONLY
return manhattan distance |goal.x-node.x| + |goal.y-nodey|

CREATE_OUTGOING_EDGES(PriorityQueue EdgesToProcess, Node)
For each child connected to node, create an edge except for parent to Node, return EdgesToProcess

CREATE_PATH(Goal,Start,PathList)
{
    Create Start Nodestruct
    Create Open/Closed Priority Queues
    Add Start Nodestruct to Open List
    
    While(OpenList != Empty)
    {
        Get the next best node from open list: Smallest CostSoFar (DIJKSTRA) or Smallest Total Estimated Cost (A*)
        If node is the goal, break
        
        Create a deque of outgoing edges from node
        For(each edge in deque)
        {
            Get the child node from the edge
            Child cost so far = node cost so far + edge cost
            
            if(Child is in Closed List)
            {
                if stored cost so far < new cost so far
                    continue to next node
                else
                    remove from closed list
                    update heuristic using new cost so far (A* ONLY)
            }

            else if(Child is in Open List)
            {
                Repeat but with open list
            }   

            else if(Child has not been visited)
            {
                Create new Heuristic/NodeStruct for child
            }
            
            Update all values for the childs nodestruct
            Add to Open List
        }
        
        Once all edges are done, add node to closed list
    }
    Once all nodes are done, check if in goal node
    If not, failed
    If so, create path backwards from goal node and return
}
