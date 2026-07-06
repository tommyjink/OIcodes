---
name: oi-comprehensive-coding-style
description: "Complete coding style rules for Chinese OI C++ code — indentation, braces, naming, macros, arrays, spacing, everything."
metadata: 
  node_type: memory
  type: feedback
  originSessionId: b380ebc4-fd73-4fa7-971e-166cbce3fc93
---

# Comprehensive OI Coding Style

## File Header (in order)
```
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
```
- No spaces: `#include<bits/stdc++.h>` not `#include <bits/stdc++.h>`
- No space: `using namespace std;` not `using namespace std ;`
- `pii` macro: include it even if not used in the current file

## Indentation
- **4 spaces**, NOT tabs
- Consistent across all blocks and continuations

## Braces
- **Opening braces always go on the NEXT line** when braces are needed, including functions, loops, conditionals, structs, and while blocks.
  ```cpp
  signed main()
  {
  ```
- **Control flow** (`if`/`for`/`while`): opening brace on the NEXT line
  ```cpp
  for(int i=1;i<=n;i++)
  {
  ```
- **Single-line bodies generally do NOT use braces**:
  ```cpp
  if(!tag[i])merge(x,y);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
  ```
- **Struct**: multi-line with fields on one line
  ```cpp
  struct node
  {
      int to,next,val;
  }e[N*2];
  ```

## Spacing
- No spaces inside `for(...)` / `if(...)` parentheses: `for(int i=1;i<=n;i++)`
- No spaces around `<<` / `>>`: `cout<<ans<<endl;` / `cin>>n>>m;`
- No spaces in function calls: `add(x,y,z);`
- No spaces around `=` / `+=` / binary operators: `ans=0;`, `t1[i]+=w;`
- Exception: subtle expressions can have space for clarity: `int mid=(l+r)>>1;`

## Output
- Prefer allowing a trailing space at the end of a line rather than writing special separator logic:
  ```cpp
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
  cout<<endl;
  ```
- Do NOT use tricks like `cout<<ans[i]<<" \n"[i==n];`.
- Do NOT add `if(i==n)` / `if(i<n)` branches only to avoid the final extra space.

## Variable Naming
- **All lowercase**, short, NO CamelCase
- Single letters: `n,m,k,ans,tot,i,j,l,r,c,x,y,z`
- Short abbreviations: `dis,dep,val,ch,pr,cur,nxt,flg,nd`
- Prefix patterns: `mdis` (max dis), `mnum` (max num), `nt` (next)
- Loop counters: `i,j,k` for nested loops

## Global Arrays
- **All arrays at file scope** (global), never `vector` local variables
- Sized with constants: `const int N=1e5+10;` then `int a[N];`
- Multiple vars on one line: `int n,m,head[N],tot=0;`
- Initialize at declaration: `int ans=0;`
- Use `vector<int>` only when size is truly unknown at compile time
- `memset` for initialization: `memset(dis,127,sizeof(dis));`

## Constants
- Single uppercase letter: `const int N=1e5+10;`
- Multiple on one line: `const int N=1e6+100,M=5e6;`
- Modulus: `const int mod=1e9+7;` or `const int P=998244353;`

## Functions
- Short lowercase names: `add,cal,init,dfs,solve,check,qpow,build`
- Parameters compact: `(int x,int y,int z)` no space after comma
- `void` for no return, `int` for return (becomes `long long` via macro)
- No `return;` at end of void functions

## signed main()
- Always `signed main()` (to match `#define int long long`)
- Brace on next line
- `ios::sync_with_stdio(false);` + `cin.tie(nullptr);` on separate lines
- No `cout.tie(0)` needed

## Comments
- `//` with Chinese text or short note
- `//` for commented-out debug prints
- Not excessive; remove English explanatory comments from foreign code

## Why:
The user explicitly corrected multiple styled files for using tabs, same-line function braces, CamelCase variable names, `vector` local variables, and excessive spacing. Studied ~20 of the user's original C++ files to derive the complete style spec.
## How to apply:
When rewriting any C++ file to match the user's style, follow EVERY rule above. The most frequently missed: 4-space indentation (not tabs), all opening braces on the next line when braces are needed, omit braces for simple one-line bodies, no CamelCase variable names, global arrays instead of local `vector`, and no output separator tricks like `" \n"[i==n]`.
