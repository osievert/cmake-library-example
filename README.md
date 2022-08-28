# cmake-library-example

A little example to play with static and dynamic library integration.

Questions this example answers:
- Will cmake link a static library into a dynamic library?
- On all platforms (macOS, Windows, Linux)?
- What cmake incantations are necessary?

Part of some ruminations about the future of dynamic libraries. Dynamic libraries
are required in certain situations, but should we be using them outside of those?
The easy answer is "make everything a dynamic library everywhere all the time" but
I question the wisdom of that approach .. at least the universality of its
application. Dynamic libraries certainly have their place, but should we be reaching
for them by default? More and more I lean towards "no", but that forces us to face
some integration issues in complicated projects:

- In a project that must use a dynamic library, can we aggregate static libraries
  into those dynamic libraries?

- In a project where several such dynamic libraries exist, what happens when
  multiple dynamic libraries integrate the same static library? This is the
  point where most projects throw up their hands and say "everything should
  be a dynamic library" .. is there a different option?

