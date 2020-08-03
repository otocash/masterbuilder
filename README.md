
[<img src="https://github.com/otocash/otocash/blob/master/src/qt/res/images/githubbanner.png">](https://www.otocash.io)

OTOCASH Core V1.1.2 
===================
[![Build Status](https://travis-ci.org/otocash/masterbuilder.svg?branch=master)](https://travis-ci.org/otocash/otocash)
[![License][license-badge]][license-page]
[![Read the Docs](https://readthedocs.org/projects/yt2mp3/badge/?version=latest)](https://www.otocash.io/otocash_documentation/)
[![Version](https://badge.fury.io/gh/tterb%2FHyde.svg)](https://github.com/otocash/OTOCASH/releases/tag/v1.1.2.1)
[![Twitter Follow](https://img.shields.io/twitter/follow/otocashofficial.svg?style=social)](https://twitter.com/otocashofficial)
[![Discord Chat](https://img.shields.io/discord/308323056592486420.svg)](https://t.me/otocashofficial)  

[license-page]: LICENSE
[license-badge]: http://img.shields.io/badge/License-MIT-brightgreen.svg

Copyright (c) 2018-2020 OTO CASH ENTERPRISE

What is OTOCASH?
----------------

OTOCASH (OTO) is a Scrypt-PoS Based Cryptocurrency, OTOCASH coin will be used on OTOCASH PAYMENT SYSTEM platform that enables buyers to use their OTO Coin’s in order to pay sellers (private or merchants). We provide user or merchants with the safety and convenience with KYC and offer the best consumer-protection to buyers and sellers.

### Coin Specs
<table>
<tr><td>Max Coin Supply</td><td>Unlimited</td></tr>
<tr><td>Type</td><td>POS </td></tr>
<tr><td>Algo</td><td>Script-PoS</td></tr>
<tr><td>Average Block Time</td><td>140 Seconds</td></tr>
<tr><td>Maturity</td><td>10 Confirmations</td></tr>
<tr><td>Reward</td><td>0.25 OTO</td></tr>
<tr><td>Fee</td><td>0.000001 OTO</td></tr>
<tr><td>Protocol#</td><td>120011</td></tr>
<tr><td>P2P port</td><td>7011</td></tr>
<tr><td>RPC port</td><td>7012</td></tr>
<tr><td>Premine</td><td>38254582 OTO*</td></tr>
</table>

*View Coin Distribution on [otocash.io](https://www.otocash.io/#distribution)

### Reward Distribution
For more information, as well as an immediately useable, binary version of
the OTOCASH client sofware, see https://www.otocash.io/otocash_documentation/.


Development Process
-------------------

The `master` branch is meant to be stable. Developers work in their own trees, then submit pull requests when they think their feature or bug fix is ready.. [Tags](https://github.com/otocash/OTOCASH/tags) are created to indicate new official,stable release versions of OTOCASH Core.

The patch will be accepted if there is broad consensus that it is a good thing.  Developers should expect to rework and resubmit patches if they don't match the project's coding conventions [coding.txt](/doc/coding.txt) or are controversial.

The master branch is regularly built and tested, but is not guaranteed to be completely stable. Tags are regularly created to indicate new stable release versions of OTOCASH.

From time to time a pull request will become outdated. If this occurs, and the pull is no longer automatically mergeable; a comment on the pull will be used to issue a warning of closure. The pull will be closed 15 days after the warning if action is not taken by the author. Pull requests closed in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after 15 days from their last activity. Issues closed in this manner will be labeled 'stale'.


### Building & Deploy

See  [readme-qt](/doc/readme-qt.rst) and [coding.txt](/doc/coding.txt) for instructions on building OTOCASH QT,the intended-for-end-users, nice-graphical-interface, reference implementation of OTOCASH.

See [build-msw.txt](/doc/build-msw.txt) , [build-osx.txt](/doc/build-osx.txt) or [build-unix.txt](/doc/build-unix.txt) for instructions on building otocashd,the intended-for-services, no-graphical-interface, reference implementation of OTOCASH.


OTOCASH peer list

```
- 104.168.99.53:7011	    /Otocash:v1.1.2/	 
- 185.136.163.178:7011      /Otocash:v1.1.2/	
- 198.54.121.78:7011	    /Otocash:v1.0.1/ 
- 111.90.150.205:7011       /Otocash:v1.1.2/  
- 161.129.65.4:7011         /Otocash:v1.1.2/ 
- 111.90.146.78:7011        /Otocash:v1.1.2/ 
- 111.90.151.137:7011       /Otocash:v1.1.2/ 
- 198.54.121.69:7011        /Otocash:v1.1.2/ 
- 107.152.213.111:7011      /Otocash:v1.1.2/
- 185.136.163.114:7011      /Otocash:v1.1.2/ 
- 128.199.231.10:7011       /Otocash:v1.1.2/ 
- 128.199.225.197:7011      /Otocash:v1.1.2/ 
```

Copy this nodes to your wallet .conf file
If you have problem to sync your wallet with Otocash blockchain - use the following nodes to fix it.

```
- addnode=104.168.99.53:7011
- addnode=185.136.163.178:7011 
- addnode=198.54.121.78:7011
- addnode=111.90.150.205:7011
- addnode=161.129.65.4:7011 
- addnode=111.90.146.78:7011
- addnode=111.90.151.137:7011 
- addnode=198.54.121.69:7011
- addnode=107.152.213.111:7011 
- addnode=185.136.163.114:7011
- addnode=128.199.231.10:7011
- addnode=128.199.225.197:7011
```




Testing
-------

Testing ([README](/src/test/README)) and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

OTOCASH testnet node

```
- 185.136.169.110:17011	    /Otocash:v1.0.1/	
```
Copy this nodes to your wallet .conf file

```
- addnode=185.136.169.110:17011
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

Report An Issues 
----------------

This is the second [release](https://github.com/otocash/OTOCASH/releases) of OTOCASH Core if you find any bugs, Please report using the issue tracker on GitHub:

https://github.com/otocash/OTOCASH/issues

Disclaimer
-------------------

OTOCASH project is The Future Financial System Currency.
Invest at your own risk.

