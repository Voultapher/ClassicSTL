## Lab 5: Iterator Invalidation

In this lab, you'll fix a couple of semi-realistic bugs related to
reference invalidation and iterator invalidation.


### Getting started

A buggy C++ program is present in the `partial/` directory. You should start
from there.

Run `make` to build the project; then run `./lab5`. Notice that both
tests produce incorrect output. It's possible that they even crash on your
machine! (They don't crash on my machine, but they do both have undefined
behavior, so anything is possible.)


### Diagnose and fix the two snippets

Diagnose the misbehavior in `firstTest`. In a real codebase, where the caller
and callee were written by different people, how would you apportion blame
for this bug? How would you avoid bugs like this in the future?

Diagnose the misbehavior in `secondTest`.

It's fairly indisputable that this code is too complicated; if you replace
`first` and `last` with `team.begin()` and `team.end()`, the bug goes away.
In a real codebase, if it were proven that the `first`/`last` optimization
were actually key to performance, what could you do to fix the bug while
preserving the optimization?


### Bonus challenges

Fix the bug in `firstTest`, in the best way possible. The _smallest_ fix
possible is a diff of only a single character, but I don't think it's the
_best_ fix. (There is no single correct answer here.)

Fix the bug in `secondTest`, in the best way possible. The _smallest_ fix
possible is to replace `vector` with a different container — which one?
Why does this fix the symptom? Do you think you've actually fixed the bug,
or just papered over it temporarily? (There is no single correct answer here.)

Read and understand the code in `reverse_find.hpp`.
(It is _not_ intended to be buggy.)
How does `reverse_find` differ from `find_last`?
