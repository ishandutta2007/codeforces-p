@file:Suppress("CanBeVal")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.lang.Math.min
import java.util.*
import kotlin.time.seconds

private fun solveTest() {
    var n = readInt()
    var a = readInts(n)
    var b = readInts(n)
    var aa = Array(n) { i ->
        Pair(a[i], i)
    }
    var bb = Array(n) { i ->
        Pair(b[i], i)
    }
    aa.sortBy { x -> x.first }
    bb.sortBy { x -> x.first }
    var res = -1
    var p = intarr(n)
    for (m in 0 until n + 1) {
        var s = Int.MAX_VALUE
        for (i in 0 until m) {
            s = Math.min(s, Math.abs(bb[n - m + i].first - aa[i].first))
        }
        for (i in 0 until n - m) {
            s = Math.min(s, Math.abs(aa[m + i].first - bb[i].first))
        }
        if (s > res) {
            res = s
            for (i in 0 until m) {
                p[aa[i].second] = bb[n - m + i].second + 1
            }
            for (i in 0 until n - m) {
                p[aa[m + i].second] = bb[i].second + 1
            }
        }
    }
    println(p)
}

private fun solve() {
    var t = readInt()
    while (t-- > 0) {
        solveTest()
    }
}


// TEMPLATE
fun main(args: Array<String>) {
    reader = BufferedReader(InputStreamReader(System.`in`))
    out = PrintWriter(OutputStreamWriter(System.out))
    solve()
    out.close()
}

private lateinit var out: PrintWriter
private lateinit var reader: BufferedReader
private var tokenizer: StringTokenizer? = null
private fun read(): String {
    while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
        tokenizer = StringTokenizer(readLn())
    }
    return tokenizer!!.nextToken()
}

private fun readInt() = read().toInt()
private fun readLong() = read().toLong()
private fun readLn() = reader.readLine()!!
private fun readInts() = readLn().split(" ").map { it.toInt() }
private fun readInts(sz: Int) = Array(sz) { readInt() }
private fun readLongs() = readLn().split(" ").map { it.toLong() }
private fun readLongs(sz: Int) = Array(sz) { readLong() }
private fun print(b: Boolean) = out.print(b)
private fun print(i: Int) = out.print(i)
private fun print(d: Double) = out.print(d)
private fun print(l: Long) = out.print(l)
private fun print(s: String) = out.print(s)
private fun print(message: Any?) = out.print(message)
private fun print(a: Array<Int>) = a.forEach { print("$it ") }
private fun <T> print(a: Array<out T>) = a.forEach { print("$it ") }
private fun <T> print(a: Collection<T>) = a.forEach { print("$it ") }
private fun println(b: Boolean) = out.println(b)
private fun println(i: Int) = out.println(i)
private fun println(d: Double) = out.println(d)
private fun println(l: Long) = out.println(l)
private fun println(s: String) = out.println(s)
private fun println() = out.println()
private fun println(message: Any?) = out.println(message)
private fun <T> println(a: Array<out T>) {
    a.forEach { print("$it ") }
    println()
}

private fun println(a: IntArray) {
    a.forEach { print("$it ") }
    println()
}

private fun <T> println(a: Collection<T>) {
    a.forEach { print("$it ") }
    println()
}

private fun intarr(sz: Int, v: Int = 0) = IntArray(sz) { v }
private fun longarr(sz: Int, v: Long = 0) = LongArray(sz) { v }
private fun intarr2d(n: Int, m: Int, v: Int = 0) = Array(n) { intarr(m, v) }
private fun <T> init(vararg elements: T) = elements
private fun VI(n: Int = 0, init: Int = 0) = MutableList(n) { init }
private fun VVI(n: Int = 0, m: Int = 0, init: Int = 0) = MutableList(n) { VI(m, init) }
private fun <T1 : Comparable<T1>, T2 : Comparable<T2>> pairCmp(): Comparator<Pair<T1, T2>> {
    return Comparator { a, b ->
        val res = a.first.compareTo(b.first)
        if (res == 0) a.second.compareTo(b.second) else res
    }
}