uses math;

const inf = 2147483647;

var n,m,p,q,t   : int64;
    l,r         : longint;
    i,j,k       : longint;
    x,y,z       : longint;
    cnt,ans     : int64;
    a           : array[1..1048575] of longint;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

    depth       : longint;
    fn          : longint;

procedure swap (var a,b : longint);var t : longint;begin t := a;a := b;b := t;end;
procedure swapc(var a,b : char)   ;var t : char;   begin t := a;a := b;b := t;end;

function gcd  (a,b : longint):longint;var t : longint;begin while a > 0 do begin t := a;a := b mod a;b := t;end;gcd := b;end;

begin
     readln(n,m);

     p := n div 2 + n mod 2;

     if (m <= p)
     then writeln(m*2-1)
     else writeln((m-p)*2);
end.