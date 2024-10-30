import java.lang.AssertionError
import java.util.*

val readQueue = ArrayDeque<String>()
fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let{ readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getLong() = getInput().toLong()
fun getString() = getInput()

const val MOD107 = 1000000007L
const val MOD998 = 998244353L
fun myAssert(b : Boolean) {
    if (!b) throw AssertionError()
}

fun main() {
    var q = getInt()
    while (q-- > 0) {
        var s = StringBuilder(getInput())
        var t = StringBuilder(getInput())

        var can = true
        while (!s.isEmpty() && !t.isEmpty()) {
            if (s.last() == t.last()) {
                s.setLength(s.length - 1)
                t.setLength(t.length - 1)
            }
            else if (s.length >= 2 && s.substring(s.length - 2, s.length) == "--" && t.last() == '+') {
                s.setLength(s.length - 2)
                t.setLength(t.length - 1)
            }
            else {
                can = false
                break
            }
        }

        if (!s.isEmpty() || !t.isEmpty())
            can = false

        println(if (can) "YES" else "NO")
    }
}