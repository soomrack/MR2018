This project is an implementation of an image recognition service that works as a web server.

-------------------------

Modules:
1. server
2. CLI client

~~~~~~~~~~~~~~~~~~~~~

Usage:
tcp_CLIENT <path to image> [-p <port number> -a <ip adress>]
Example:
tcp_CLIENT car.jpg -a 192.168.0.1 -p 1024

-p --port - default is 20180

-a --address - default is 127.0.0.1

Supported image formats are: .jpg, .jpeg

~~~~~~~~~~~~~~~~~~~~~

To make client available as a bash command use the command like this:

user@user~ echo 'export PATH="$PATH":/path/to/web_nn_service' >> /home/user/.bashrc

~~~~~~~~~~~~~~~~~~~~~

setup server:

1. ./server/install_daemon.sh (requires root?)
2. sudo systemctl start web_nn_server
3. to use the service over the internet your machine should have static ip or port should be forwarded through the firewall

~~~~~~~~~~~~~~~~~~~~

You can modify the following constants in the config file (config/config.json):

const char DEFAULT_TCP_SERVER_ADRESS[] = "127.0.0.1";
const int DEFAULT_TCP_SERVER_PORT = 20180;

const double IOU_THRESHOLD = 0.3;
const double OBJECTNESS_THRESHOLD = 0.8;
