let foo: int = 42;
let bar: float = 42.0;

// Js.log(foo == bar);  // Won't compile:

Js.log(foo == Int.of_float(bar));
Js.log(Float.of_int(foo) == bar);

// Js.log(42 + 42.0);  // Won't compile
Js.log(42.0 +. 16.0);

Js.log(Js.typeof(foo)); // number
Js.log(Js.typeof(bar)); // number

let baz: int64 = 42_000_000_000L;
Js.log(baz);

Js.log(Int64.add(42L, 16L));
