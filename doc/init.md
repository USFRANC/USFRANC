Sample init scripts and service configuration for usfrancd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the `contrib/init` folder.

Service User
---------------------------------

All three Linux startup configurations assume the existence of a `usfranc` user
and group. They must be created before attempting to use these scripts.
The macOS configuration assumes `usfrancd` will be set up for the current user.

Configuration
---------------------------------

Running `usfrancd` as a daemon does not require any manual configuration. You may
set the `rpcauth` setting in the `usfranc.conf` configuration file to override
the default behaviour of using a special cookie for authentication.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that `usfrancd` and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If `usfrancd` is run with the `-server` flag (set by default), and no `rpcpassword` is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but its location can be overridden
with the option `-rpccookiefile`.

This allows for running `usfrancd` without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/usfrancd`
Configuration file:  `/etc/usfranc/usfranc.conf`
Data directory:      `/var/lib/usfrancd`
PID file:            `/var/run/usfrancd/usfrancd.pid` (OpenRC and Upstart) or `/run/usfrancd/usfrancd.pid` (systemd)
Lock file:           `/var/lock/subsys/usfrancd` (CentOS)

The PID directory (if applicable) and data directory should both be owned by the
`usfranc` user and group. It is advised for security reasons to make the
configuration file and data directory only readable by the `usfranc` user and
group. Access to `usfranc-cli` and other `usfrancd` RPC clients can then be
controlled by group membership.

### macOS

Binary:              `/usr/local/bin/usfrancd`
Configuration file:  `~/Library/Application Support/USFranc/usfranc.conf`
Data directory:      `~/Library/Application Support/USFranc`
Lock file:           `~/Library/Application Support/USFranc/.lock`

Installing Service Configuration
-----------------------------------

### systemd

Installing this `.service` file consists of copying it to
`/usr/lib/systemd/system` directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start usfrancd` and to enable for system startup run
`systemctl enable usfrancd`.

NOTE: When installing for systemd in Debian/Ubuntu the `.service` file needs to be copied to the `/lib/systemd/system` directory instead.

### OpenRC

Rename the `.openrc` script to `usfrancd` and drop it in `/etc/init.d`. Double
check ownership and permissions and make it executable. Test it with
`/etc/init.d/usfrancd start` and configure it to run on startup with
`rc-update add usfrancd`.

### Upstart (for Debian/Ubuntu based distributions)

Upstart is the default init system for Debian/Ubuntu versions older than 15.04. If you are using version 15.04 or newer and haven't manually configured upstart you should follow the systemd instructions instead.

Drop `usfrancd.conf` in `/etc/init`. Test by running `service usfrancd start`;
it will automatically start on reboot.

### CentOS

Copy the `.init` script to `/etc/init.d/usfrancd`. Test by running `service usfrancd start`.

### macOS

Copy the `.plist` file into `~/Library/LaunchAgents`. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.usfranc.usfrancd.plist`.

This Launch Agent will cause `usfrancd` to start whenever the user logs in.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen.
