Sample configuration files for `usfrancd`:
```
SystemD: bitcoind.service
Upstart: bitcoind.conf
OpenRC:  bitcoind.openrc
         bitcoind.openrcconf
CentOS:  bitcoind.init
macOS:   org.bitcoin.bitcoind.plist
```
have been made available to assist packagers in creating USFranc Core node packages here (adapt the service and binary paths to `usfrancd` and `usfranc.conf` when deploying).

See [doc/init.md](../../doc/init.md) for more information.
