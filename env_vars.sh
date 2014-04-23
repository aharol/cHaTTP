#!/bin/bash

# Message broker configuration.
# May also used to initialize other parts of cHaTTP.
# Just source this script (`source env_vars.sh`)

##### Application bind information

# The bind address of the webapp backend.
export CHATTP_WEBAPP_ADDR="/tmp/webapp"
export CHATTP_WEBAPP_FAMILY="UNIX"
export CHATTP_WEBAPP_PORT=""

# The bind address of the message relay application.
export CHATTP_MESG_RELAY_ADDR="/tmp/message-relay"
export CHATTP_MESG_RELAY_FAMILY="UNIX"
export CHATTP_MESG_RELAY_PORT=""

# The bind address of the persistence layer.
export CHATTP_PERSISTENCE_LAYER_ADDR="/tmp/persistence-layer"
export CHATTP_PERSISTENCE_LAYER_FAMILY="UNIX"
export CHATTP_PERSISTENCE_LAYER_PORT=""

##### Message broker bind ports -- the message broker as 4 sockets, each dedicated to one external application
##### The address family is the same one as in the application bind addresses above.

# This one is used by the persistence layer
export CHATTP_MSGBROKER_PERSISTENCE_BIND_ADDR="/tmp/msg-broker-persistence"
export CHATTP_MSGBROKER_PERSISTENCE_BIND_PORT=""

# On this socket, the message relay may contact the broker
export CHATTP_MSGBROKER_MSGRELAY_BIND_ADDR="/tmp/msg-broker-msgrelay"
export CHATTP_MSGBROKER_MSGRELAY_BIND_PORT=""

# The webapp uses this socket to communicate with the broker
export CHATTP_MSGBROKER_WEBAPP_BIND_ADDR="/tmp/msg-broker-webapp"
export CHATTP_MSGBROKER_WEBAPP_BIND_PORT=""

# This is the host on which the broker listens. It should be a FQDN because
# it's also used in the persistence layer as identification string for a user's location.
# Other message brokers contacting the one on this host should be able to resolve this name.
export CHATTP_MSGBROKER_BROKER_NAME="vostro-linux.virt.goebo.site"

##### General application configuration

# Not more than the number of processors/cores in your machine.
export CHATTP_MSGBROKER_NUMBER_THREADS="3"

