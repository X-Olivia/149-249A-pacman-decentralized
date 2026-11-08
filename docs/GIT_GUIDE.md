# Git Guide for Our Team

Short rules so we don't break each other's work. When in doubt, ask in the group chat before you push.

## The 5 rules

1. **Never commit directly to `main`.** Do all work on your own branch and merge through a Pull Request (PR).
2. **One branch per task.** Give it a short, descriptive name, e.g. `sim-maze-uwb`, `bluetooth-drive`, `fix-ghost-turning`.
3. **Pull before you start, and before you open a PR.** This keeps your branch up to date with `main`.
4. **Commit small and often.** Each commit should do one thing.
5. **Someone else reviews every PR before it is merged.** Don't merge your own PR without at least one teammate looking at it.

## Daily workflow

```bash
# 1. Start from an up-to-date main
git checkout main
git pull origin main

# 2. Create your branch
git checkout -b my-task-name

# 3. Work, then check what changed
git status              # which files changed
git diff                # what exactly changed

# 4. Stage and commit
git add .                                # add everything that changed, or
git add simulation/ghost.py simulation/sim.py   # add only the files you name
git commit -m "ghost picks exit closest to Pac-Man"

# 5. Push your branch (first time: -u)
git push -u origin my-task-name
```

**Adding only some files:** run `git status` to see what changed, then `git add` just the files you want in this commit (list them with spaces). `git add -u` adds every modified file that git already tracks, but skips new files. If you added a file by mistake, `git restore --staged <file>` un-stages it (your edits are kept).

Then open a PR on GitHub from `my-task-name` into `main`, describe what you did and how to test it, and ask a teammate to review.

## Keeping your branch up to date

If `main` changed while you were working:

```bash
git checkout main
git pull origin main
git checkout my-task-name
git merge main          # bring the new main into your branch
# fix any conflicts, then:
git add <fixed files>
git commit
git push
```

### Fixing a merge conflict

Git marks the conflict inside the file like this:

```
<<<<<<< HEAD
your version
=======
their version
>>>>>>> main
```

Edit the file to keep the right code, delete the `<<<<<<<`, `=======`, `>>>>>>>` lines, then `git add` the file and `git commit`. If you are unsure, ask the person who wrote the other version.

## Undo a commit you haven't pushed yet

```bash
git reset --soft HEAD~1      # undo the last commit, keep your changes
```

Never use `git push --force` on a shared branch without asking the team first.

## Working on someone else's branch

- Ask first.
- Prefer creating your own branch from theirs (`git checkout -b my-change origin/their-branch`) and opening a PR into their branch.
- Never rewrite history (`rebase`, `reset`, `push --force`) on a branch someone else is using.

## Useful commands

| Command | What it does |
|---|---|
| `git status` | What changed, what is staged |
| `git log --oneline --graph --all` | History of all branches |
| `git branch -a` | List local and remote branches |
| `git fetch origin` | Download new remote branches without changing your files |
| `git stash` / `git stash pop` | Put unfinished changes aside / bring them back |
| `git restore <file>` | Throw away your local changes to a file (careful!) |
| `git diff main...my-branch` | What your branch changes compared with main |
