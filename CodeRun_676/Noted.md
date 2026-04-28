04.10.2025
18:06

Note for the task "mom, supermarket, pickup point"

Points:
H — home
S — supermarket
P — pickup point

Distances:
a = H <-> S
b = H <-> P
c = S <-> P

Velocities:
v0 — walking empty-handed
v1 — carrying one item
v2 — carrying two items


1. How to logically arrive at MinimalA / MinimalB / MinimalC?

The key idea is that a, b, and c are not necessarily the shortest distances between points.

For example, to get from home to the supermarket, we can go:
- directly: H -> S = a
- through the pickup point: H -> P -> S = b + c

So the actual minimum distance between H and S is:

    MinimalA = min(a, b + c)

Similarly:

    MinimalB = min(b, a + c)  // H <-> P
    MinimalC = min(c, a + b)  // S <-> P

In other words, first we "compress" the triangle:
each distance is replaced with the shortest path between two points.


2. How do we know that we have checked enough routes?

After calculating MinimalA / MinimalB / MinimalC, all physical detours are already included.

Only the meaningful delivery strategies remain:

1) Bring the products and the package separately:

    H -> S -> H -> P -> H

    Time = A/v0 + A/v1 + B/v0 + B/v1

The order can be reversed:

    H -> P -> H -> S -> H

But the formula will be the same, so this is not a separate case.


2) Supermarket first, then pickup point:

    H -> S -> P -> H

    Time = A/v0 + C/v1 + B/v2


3) Pickup point first, then supermarket:

    H -> P -> S -> H

    Time = B/v0 + C/v1 + A/v2


So it is enough to check 3 cases:

    Separate
    ShopThenPickup
    PickupThenShop

The answer is the minimum of them.


3. What if it is allowed to visit a point and take nothing there?

If it is allowed to visit a point and take nothing, then MinimalA / MinimalB / MinimalC can be used.

For example:

    A = min(a, b + c)

may mean that the path H -> S is physically:

    H -> P -> S

But at P we do not take anything; we simply pass through this point.

If visiting a point forces the action:
- arrived at the supermarket -> must buy the products
- arrived at the pickup point -> must take the package

then simple distance normalization may become incorrect.

In that case, it is better to solve the task as a state graph:

    state = current position + what has already been taken + what has already been delivered home

Then search for the minimum time in this graph.

P.S. Moral Destruction for me.