

<WritingBlock id="73108" variant="document"># Git Basics for DSA Preparation

## Objective

Use Git to track your DSA solutions and record your progress.

## What Is Git?

Git is a version control system. It records changes to your files so you can review your work and return to earlier versions.

## What Is GitHub?

GitHub hosts Git repositories online, allowing you to back up and share your work.

## Step 1: Install Git

Download Git from:

[https://git-scm.com/](https://git-scm.com/)

Verify installation:

## Step 2: Configure Your Identity

Bash

```
git config --global user.name "Your Name"
git config --global user.email "your-email@example.com"
```

Use an email address appropriate for your GitHub account.

## Step 3: Initialize Your Repository

Open a terminal in your `DSA-Placement-Preparation` directory:

Bash

```
git init
```

Check the current state:

Bash

```
git status
```

## Step 4: Stage and Commit Files

Stage all changes:

Bash

```
git add .
```

Create a commit:

Bash

```
git commit -m "Add initial DSA setup"
```

A commit records a snapshot of your staged changes.

## Step 5: Useful Commands

Check repository status:

Bash

```
git status
```

View recent commits:

Bash

```
git log --oneline
```

View changes not yet staged:

Bash

```
git diff
```

Stage a specific file:

Bash

```
git add 04_Arrays/reverse_array.cpp
```

Commit a topic:

Bash

```
git commit -m "Practice basic array problems"
```

## Recommended Commit Messages

* `Add C++ fundamentals examples`

* `Solve array traversal problems`

* `Implement binary search`

* `Add linked list practice`

* `Fix recursion base case`

* `Update DSA progress tracker`

## Important Rules

* Commit working, meaningful changes.

* Do not commit passwords, API keys, or private credentials.

* Do not commit generated executables unless you have a specific reason.

* Check `git status` before committing.

* Write commit messages that describe what changed.

## Completion Checklist

* Git installed.

* Identity configured.

* Repository initialized.

* First commit created.

* `git status` understood.</WritingBlock>
