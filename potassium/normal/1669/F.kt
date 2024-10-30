import java.lang.AssertionError
import java.lang.StringBuilder
import java.math.BigInteger
import java.util.*
import kotlin.math.*

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
    var t = getInt()
    println((0 until t).map {
        var n = getInt()
        var a = Array(n) { getInt() }

        var ls = 0
        var rs = 0
        var l = 0
        var r = n
        var ans = 0
        for (l in 0 until n) {
            ls += a[l]
            while (r - 1 > l && rs + a[r - 1] <= ls) {
                r--
                rs += a[r]
            }

            if (ls == rs)
                ans = l + 1 + n - r
        }

        ans
    }.joinToString("\n"))
}