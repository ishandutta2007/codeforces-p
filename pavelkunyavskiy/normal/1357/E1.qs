namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        for (i in 0..(p % 4)-1) {
          QFTLE(inputRegister);
        }
    }
}