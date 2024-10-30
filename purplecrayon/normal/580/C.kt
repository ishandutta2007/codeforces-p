import java.util.*


/** IO */
//@JvmField val ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null
//const val PATH = "src/main/resources/"
//@JvmField val INPUT = File(PATH + "input.txt").inputStream()
//@JvmField val OUTPUT = File(PATH + "output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

const val _BUFFER_SIZE = 1 shl 16
@JvmField val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField var _bufferPt = 0
@JvmField var _bytesRead = 0

tailrec fun readChar(): Char {
    if(_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if(_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar() else c
    }
}
fun readLine(): String? {
    var c = readChar()
    return if(c == Char.MIN_VALUE) null
    else buildString {
        while(c != '\n' && c != Char.MIN_VALUE) {
            append(c)
            c = readChar()
        }
    }
}
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun dfs(c: Int, p: Int, cnt: Int, a: BooleanArray, adj: MutableList<MutableList<Int>>, m: Int): Int {
    var new_cnt = cnt;
    if (a[c]) {
        new_cnt++;
    } else {
        new_cnt = 0;
    }
    if (new_cnt > m) {
        return 0;
    }
    var ans = 0;
    if (c != 0 && adj[c].size == 1) {
        ans++;
    }
    for (nxt in adj[c]) {
        if (nxt == p) continue;
        ans += dfs(nxt, c, new_cnt, a, adj, m);
    }
    return ans;
}
fun solve() {
    var (n, m) = readInts();
    var a = BooleanArray(n);
    var _a = readInts();
    for (i in 0 until n) {
        a[i] = _a[i] == 1;
    }
    var adj = MutableList(n) { _ -> mutableListOf<Int>()}
    repeat(n-1) {
        var (a, b) = readInts();
        a--; b--;
        adj[a].add(b);
        adj[b].add(a);
    }
    var ans = dfs(0, -1, 0, a, adj, m);
    println(ans);
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}