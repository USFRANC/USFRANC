Contributing to USFranc Core
============================

The USFranc Core project operates an open contributor model where contributors are
welcome to participate in development in the form of peer review, testing
and patches. This document explains the practical process and guidelines for
contributing.

Getting Started
---------------

Reviewing and testing is highly valued and the most effective way you can contribute
as a new contributor. It also will teach you much more about the code and
process than opening pull requests. Please refer to the [peer review](#peer-review)
section below.

Before you start contributing, familiarize yourself with the USFranc Core build
system and tests. Refer to the documentation in the repository on how to build
USFranc Core and how to run the unit tests, functional tests, and fuzz tests.

Contributor Workflow
--------------------

The codebase is maintained using the "contributor workflow" where everyone
without exception contributes patch proposals using "pull requests" (PRs). This
facilitates social contribution, easy testing and peer review.

To contribute a patch, the workflow is as follows:

  1. Fork repository
  2. Create topic branch
  3. Commit patches

The project coding conventions in the [developer notes](doc/developer-notes.md)
must be followed.

### Committing Patches

In general, [commits should be atomic](https://en.wikipedia.org/wiki/Atomic_commit#Atomic_commit_convention)
and diffs should be easy to read. For this reason, do not mix any formatting
fixes or code moves with actual code changes.

Make sure each individual commit is hygienic: that it builds successfully on its
own without warnings, errors, regressions, or test failures.

Commit messages should be verbose by default consisting of a short subject line
(50 chars max), a blank line and detailed explanatory text as separate
paragraph(s), unless the title alone is self-explanatory (like "Corrected typo
in init.cpp") in which case a single title line is sufficient. Commit messages should be
helpful to people reading your code in the future, so explain the reasoning for
your decisions.

If a particular commit references another issue, please add the reference. For
example: `refs #1234` or `fixes #4321`. Using the `fixes` or `closes` keywords
will cause the corresponding issue to be closed when the pull request is merged.

Commit messages should never contain any `@` mentions (usernames prefixed with "@").

  - Push changes to your fork
  - Create pull request

### Creating the Pull Request

The title of the pull request should be prefixed by the component or area that
the pull request affects. Valid areas are:

  - `consensus` for changes to consensus critical code
  - `doc` for changes to the documentation
  - `qt` or `gui` for changes to `usfranc-qt`
  - `log` for changes to log messages
  - `mining` for changes to the mining code
  - `net` or `p2p` for changes to the peer-to-peer network code
  - `refactor` for structural changes that do not change behavior
  - `rpc`, `rest` or `zmq` for changes to the RPC, REST or ZMQ APIs
  - `script` for changes to the scripts and tools
  - `test`, `qa` or `ci` for changes to the unit tests, QA tests or CI code
  - `util` or `lib` for changes to the utils or libraries
  - `wallet` for changes to the wallet code
  - `build` for changes to the GNU Autotools or reproducible builds

Examples:

    consensus: Add new opcode for BIP-XXXX
    net: Automatically create onion service, listen on Tor
    qt: Add fee bump button
    log: Fix typo in log message

The body of the pull request should contain sufficient description of *what* the
patch does, and even more importantly, *why*, with justification and reasoning.

### Work in Progress Changes and Requests for Comments

If a pull request is not to be considered for merging (yet), please
prefix the title with `[WIP]` or use Task Lists in the body of the pull request to indicate tasks are pending.

### Address Feedback

At this stage, one should expect comments and review from other contributors. You
can add more commits to your pull request by committing them locally and pushing
to your fork until you have satisfied all feedback.

### Squashing Commits

If your pull request contains fixup commits (commits that change the same line of code repeatedly) or too fine-grained
commits, you may be asked to [squash](https://git-scm.com/docs/git-rebase#_interactive_mode) your commits
before it will be merged. The basic squashing workflow is shown below.

    git checkout your_branch_name
    git rebase -i HEAD~n
    # n is normally the number of commits in the pull request.
    # Set commits (except the one in the first line) from 'pick' to 'squash', save and quit.
    # On the next screen, edit/refine commit messages.
    # Save and quit.
    git push -f # (force push to GitHub)

### Rebasing Changes

When a pull request conflicts with the target branch, you may be asked to rebase it on top of the current target branch.
The `git rebase` command will take care of rebuilding your commits on top of the new base.

Pull Request Philosophy
-----------------------

Patchsets should always be focused. For example, a pull request could add a
feature, fix a bug, or refactor code; but not a mixture. Please also avoid super
pull requests which attempt to do too much, are overly large, or overly complex
as this makes review difficult.

"Decision Making" Process
-------------------------

The following applies to code changes to the USFranc Core project (and related
projects such as libsecp256k1), and is not to be confused with overall USFranc
Network Protocol consensus changes.

Whether a pull request is merged into USFranc Core rests with the project merge
maintainers and ultimately the project lead.

In general, all pull requests must:

  - Have a clear use case, fix a demonstrable bug or serve the greater good of
    the project (for example refactoring for modularisation);
  - Be well peer-reviewed;
  - Have unit tests, functional tests, and fuzz tests, where appropriate;
  - Follow code style guidelines ([C++](doc/developer-notes.md), [functional tests](test/functional/README.md));
  - Not break the existing test suite;
  - Where bugs are fixed, where possible, there should be unit tests
    demonstrating the bug and also proving the fix. This helps prevent regression.
  - Change relevant comments and documentation when behaviour of code changes.

Patches that change USFranc consensus rules are considerably more involved than
normal because they affect the entire ecosystem.

### Peer Review

Anyone may participate in peer review which is expressed by comments in the pull
request. Typically reviewers will review the code for obvious errors, as well as
test out the patch set and opine on the technical merits of the patch.

#### Conceptual Review

A review can be a conceptual review, where the reviewer leaves a comment:
 * `Concept (N)ACK`, meaning "I do (not) agree with the general goal of this pull
   request",
 * `Approach (N)ACK`, meaning `Concept ACK`, but "I do (not) agree with the
   approach of this change".

#### Code Review

After conceptual agreement on the change, code review can be provided. A review
begins with `ACK BRANCH_COMMIT`, where `BRANCH_COMMIT` is the top of the PR
branch, followed by a description of how the reviewer did the review.

Release Policy
--------------

The project leader is the release manager for each USFranc Core release.

Copyright
---------

By contributing to this repository, you agree to license your work under the
MIT license unless specified otherwise in `contrib/debian/copyright` or at
the top of the file itself. Any work contributed where you are not the original
author must contain its license header with the original author(s) and source.
