fun main(args: Array<String>) {
    var a=5;
    var b=10
    // way 1
    println("Using also")
    println("values before swapping ")
    println("a = "+a+" b= "+b)

    a=b.also { b=a }

    println("values after swapping ")
    println("a = "+a+" b= "+b)

    //way 2
    println("\nUsing run block")
    println("values before swapping ")
    println("a = "+a+" b= "+b)

    run { val temp = a; a = b; b = temp }

    println("values after swapping ")
    println("a = "+a+" b= "+b)

    //way 3
    println("\nUsing with method")
    println("values before swapping ")
    println("a = "+a+" b= "+b)
    with(a) {
        a = b
        b = this
    }
    println("values after swapping ")
    println("a = "+a+" b= "+b)

    //way 4
    println("\nSwapping mutable values using destructuring declaration")
    val c = 1
    val d = 2
    println("values before swapping ")
    println("a = "+c+" b= "+d)


    val (a2, b2) = d to c

    println("values after swapping ")
    println("a = "+a2+" b= "+b2)
}
