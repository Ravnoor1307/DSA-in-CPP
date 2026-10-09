
<WritingBlock id="73109" variant="document"># GitHub Workflow for DSA Placement Preparation

## Objective

Back up your DSA repository and maintain a history of your coding practice.

## Step 1: Create a GitHub Account

Visit:

[https://github.com/](https://github.com/)

Create an account or sign in.

## Step 2: Create a Remote Repository

1. Select New repository.

2. Name it `DSA-Placement-Preparation`.

3. Choose Public or Private according to your preference.

4. If you already have local files, avoid initializing the remote repository with a README, license, or `.gitignore` unless you intend to merge the initial histories.

5. Create the repository.

## Step 3: Add a `.gitignore` File

Create `.gitignore` in the root directory:

If you later need to track selected VS Code configuration files, adjust the `.vscode/` rule accordingly.

## Step 4: Connect Your Local Repository

Copy the remote repository URL from GitHub.

For HTTPS, the command typically looks like:

Bash

```
git remote add origin https://github.com/YOUR_USERNAME/DSA-Placement-Preparation.git
```

Replace `YOUR_USERNAME` with your GitHub username.

If your local repository has no commits yet, create the first commit:

Bash

```
git add .
git commit -m "Initialize DSA placement preparation"
```

Rename the current branch to `main`:

Bash

```
git branch -M main
```

Push the branch:

Bash

```
git push -u origin main
```

GitHub may prompt you to authenticate.

## Step 5: Your Daily Workflow

After solving a few problems:

Bash

```
git status
git add .
git commit -m "Solve basic array problems"
git push
```

Repeat this workflow as your repository grows.

## Step 6: Check Your Work Online

Open your repository on GitHub and verify that:

* Your topic folders are visible.

* Your `.cpp` files are uploaded.

* Your README and progress tracker are present.

* Compiled executables and private information are not uploaded.

## Suggested Weekly Routine

Daily

* Solve and test problems.

* Record mistakes.

* Commit meaningful progress.

Weekly

* Review solved problems.

* Revisit mistakes.

* Update `PROGRESS_TRACKER.md`.

* Push any remaining commits.

## Troubleshooting

### `remote origin already exists`

Inspect the configured remote:

Bash

```
git remote -v
```

If the URL is incorrect, update it:

Bash

```
git remote set-url origin https://github.com/YOUR_USERNAME/DSA-Placement-Preparation.git
```

### Push is rejected

The remote repository may contain commits that are absent locally. Inspect the repository history and follow Git's suggested integration process before pushing. Avoid force-pushing as a beginner.

### Authentication fails

Follow GitHub's current authentication instructions. Your normal account password is generally not accepted for Git-over-HTTPS authentication.

## Completion Checklist

* GitHub repository created.

* Local repository connected.

* `.gitignore` created.

* Initial commit pushed.

* New commit successfully pushed.

* Files visible on GitHub.</WritingBlock>
