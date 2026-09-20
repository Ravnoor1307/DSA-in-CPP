# 05 — Non-Primitive / Derived & User-Defined Data Structures

- Primitive types (int, char, float) hold a single value; non-primitive types combine many of them into one big package.
- Non-primitive structures split into two families: **DERIVED** (arrays, pointers) and **USER-DEFINED** (struct, class, union, enum).
- Derived types are built-in combinations of primitives; user-defined types are custom blueprints that model a real-world entity (student, account, car).
- A struct/class groups **heterogeneous** fields (name + rollNo + marks) under one variable, which can be stored in arrays, passed to functions, etc.
- Many same-type values → array/pointer first; a complete record with actions → struct/class.

## 🌍 Real-World Analogy

**Sharma ji ke register me har student ka poora record:**

| Register Ka Page (struct) | Andar Kya Hota Hai |
|---|---|
| `name` | student ka naam |
| `rollNo` | sequence number |
| `marks[3]` | 3 subjects ke score |

- **Primitive type** = page ka *ek* khana (sirf ek value).
- **Non-primitive (struct)** = poora *page* — naam + roll + marks sab ek saath.
- **Array of struct** = *puri class ki copy* — page-dar-page record.
- **Nested struct** = page me *photo chipki file* (Address ke andar city+pin).

> *Ek dabba ek hi cheez rakh sakta hai; ek almirah usse jod-kar kai cheezein.*
> Non-primitive = almirah.

## 📂 Files in this folder

| File | Purpose |
|---|---|
| `01_theory.cpp` | Derived (array/pointer) + User-defined (struct/class/enum) ka live demo, memory visual, dry-run, complexity |
| `task.cpp` | 7 tasks EASY→HARD: struct basics → array of structs → average → topper → pass/fail → nested struct → member function |

## 📌 Cheat Sheet

```
Primitive   : int, char, float, double, bool   (single value dabba)
Non-primitive:
  DERIVED       -> ARRAY (literal same-type values, contiguous), POINTER (address)
  USER-DEFINED  -> struct (default public), class (default private),
                   union (ek time par ek member memory), enum (named constants)

struct access : s1.name  (dot operator)
nested access : e.ad.city  (dot ke andar dot)
member fn     : s[i].total()   (struct me function bhi ho sakta hai)
```

## ⏱ Complexity at a glance

| Operation | Step Count | Complexity |
|---|---|---|
| Create 1 object | 1 allocation | f(n) = 1 → **O(1)** |
| Access a field (`s1.rollNo`) | 1 memory read | f(n) = 1 → **O(1)** |
| Traverse marks[0..n-1] | loop n baar | f(n) = n → **O(n)** |
| Find topper among n students | n baar compare | f(n) = n → **O(n)** |
| n objects ki memory | n × 1 unit | f(n) = n → **O(n)** |

## ⚠️ Common Mistakes

1. **Class me `public:` likhna bhoolna** — members default `private` HOTE hai, phir `acc.balance` access nahi hoga. (struct me default public hota hai.)
2. **Union ke saare members ek saath mat chalao** — union ek time par sirf ek member valid rakhta hai; dusra set karte hi pehla overwrite.
3. **Array without size in struct** — `int marks[]` bina size allowed nahi (use fixed size or pointer).
4. **`enum` values ko `==` se nahi, switch/if se** compare — ha, wo ints hi hain, if theek hai.
5. **Struct copy karna bhoolna** — `Student s2 = s1;` pura record copy karta hai, pointer nahi.

## 🤝 Interview Q&A

**Q1. Derived vs User-defined data structures me farak?**
Derived (array, pointer) compiler/operators se bante hain aur homogeneous hote hain; user-defined (struct, class) programmer banata hai aur heterogeneous fields + functions rakhta hai.

**Q2. struct vs class me kya farak?**
Syntactically same; bas default access different — struct me `public`, class me `private`. (Extra: class me inheritance/encapsulation use karna standard hai.)

**Q3. union kyu use karein?**
Jab ek time par ek hi field me value ho (jaise ek variable jo int bhi ho sakta hai ya float), to union saare member share karte hain — memory bachti hai.

**Q4. Array of structs kya hota hai?**
Har element pura struct hota hai — jaise 100 students ki list. `student[i].name`, `student[i].marks[j]` se access.

**Q5. struct me function kyu allowed?**
Struct bas ek type hai; C++ me struct me functions aise hi allowed hain jaise class me — jab entity pe action chahiye (total(), avg()) to andar hi function rakh do.