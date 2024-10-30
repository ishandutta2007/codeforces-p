namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            for (k in 0..Length(x)-1)
            {
                CNOT(x[k],y);
            }
        }
    }

    operation Solution2(index : Int) : Bool { 
        body {
            mutable dum = false;
            using (register = Qubit[index+1])
            {   
                X(register[0]);
                Solve(register[0..index-1],register[index]);
                
                set dum = M(register[index])==One; 
                ResetAll(register);
            }
            return dum;
        }
    }
}