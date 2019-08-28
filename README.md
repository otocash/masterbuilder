OTOCASH Core staging tree V1.0.1 
================================

http://www.otocash.io

Copyright (c) 2018-2019 OTO CASH ENTERPRISE

[![Build Status](https://travis-ci.org/otocash/OTOCASH.svg?branch=master)](https://travis-ci.org/otocash/OTOCASH)
 / [![License][license-badge]][license-page]
[license-page]: LICENSE
[license-badge]: http://img.shields.io/badge/License-MIT-brightgreen.svg

Report An Issues 
================

This is the second [release](https://github.com/otocash/OTOCASH/releases) of OTOCASH Core if you find any bugs, Please report using the issue tracker on GitHub:

https://github.com/otocash/OTOCASH/issues

What is OTOCASH?
----------------

OTOCASH (OTO) is a Scrypt-PoS Based Cryptocurrency, OTOCASH coin will be used on OTOCASH PAYMENT SYSTEM platform that enables buyers to use their OTO Coin’s in order to pay sellers (private or merchants). We provide user or merchants with the safety and convenience with KYC and offer the best consumer-protection to buyers and sellers.

OTOCASH Coin
----------------
```
- 38254582 total coins (Premine)
- Block time: 60 seconds target
- Rewards: 0.0001 OTO per block
- Scrypt Proof of Work
- Mineable by Staking
```
For more information, as well as an immediately useable, binary version of
the OTOCASH client sofware, see https://www.otocash.io/otocash_documentation/.


Development Process
-------------------

The `master` branch is meant to be stable. Development is normally done in same branches. [Tags](https://github.com/otocash/OTOCASH/tags) are created to indicate new official,stable release versions of OTOCASH Core.

Developers work in their own trees, then submit pull requests when they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a good thing.  Developers should expect to rework and resubmit patches if they don't match the project's coding conventions [coding.txt](/doc/coding.txt) or are controversial.

The master branch is regularly built and tested, but is not guaranteed to be completely stable. Tags are regularly created to indicate new stable release versions of OTOCASH.

Feature branches are created when there are major new features being worked on by several people.

From time to time a pull request will become outdated. If this occurs, and the pull is no longer automatically mergeable; a comment on the pull will be used to issue a warning of closure. The pull will be closed 15 days after the warning if action is not taken by the author. Pull requests closed in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after 15 days from their last activity. Issues closed in this manner will be labeled 'stale'.


### Building & Deploy

See  [readme-qt](/doc/readme-qt.rst) for instructions on building OTOCASH QT,the intended-for-end-users, nice-graphical-interface, reference implementation of OTOCASH.

See doc/build-*.txt for instructions on building otocashd,the intended-for-services, no-graphical-interface, reference
implementation of OTOCASH.


OTOCASH peer list

```
- 104.168.99.53:7011	    /Satoshi:v1.0.0/	
- 104.219.248.187:7011      /Satoshi:v1.0.0/	
- 199.192.21.195:7011	    /Otocash:v1.0.1/	
- 185.136.163.178:7011      /Satoshi:v1.0.0/	
- 82.195.237.251:7011	    /Otocash:v1.0.1/	
- 199.192.26.10:7011	    /Otocash:v1.0.1/	
- 199.192.26.38:7011	    /Satoshi:v1.0.0/	
- 198.54.121.78:7011	    /Otocash:v1.0.1/
- 111.90.150.205:7011       /Satoshi:v1.0.0/ 
- 161.129.65.4:7011         /Otocash:v1.0.1/ 
- 111.90.146.78:7011        /Otocash:v1.0.1/ 
- 111.90.151.137:7011       /Otocash:v1.0.1/
```

Copy this nodes to your wallet .conf file
If you have problem to sync your wallet with Otocash blockchain - use the following nodes to fix it.

```
- addnode=104.168.99.53:7011 
- addnode=104.219.248.187:7011 
- addnode=199.192.21.195:7011
- addnode=185.136.163.178:7011 
- addnode=82.195.237.251:7011
- addnode=199.192.26.10:7011
- addnode=199.192.26.38:7011 
- addnode=198.54.121.78:7011
- addnode=111.90.150.205:7011 
- addnode=161.129.65.4:7011 
- addnode=111.90.146.78:7011 
- addnode=111.90.151.137:7011 
```


Testing
-------

Testing ([README](/src/test/README)) and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

OTOCASH testnet node

```
- 199.192.16.64:17011	    /Otocash:v1.0.1/	
```
Copy this nodes to your wallet .conf file

```
- addnode=199.192.16.64:17011
```


### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

License
-------

OTOCASH Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Disclaimer
-------------------

OTOCASH project is The Future Financial System Currency.
Invest at your own risk.


