Created by mwinstone (coldfrontlabs.ca/blog/mwinstone, twitter.com/mathewwinstone)
Sponsored by Coldfront Labs

The HSTS module (which stands for HTTP Strict Transport Security) is a means
to allow HSTS compliant clients to securely connect to your site. 

For a longer explanation, see http://en.wikipedia.org/wiki/Strict_Transport_Security

Essentially, it forces all connections between the client (typically the
web browser) and your site to use a secure connection. This includes pages,
css, images, javascript, everything.

It also blocks any attempts to make insecure connections. If anything is out
of place (i.e. invalid certificate, non-ssl connection attempt to resources,
etc...) the connection is blocked. The user can't make exceptions like they
can with traditional SSL connections.

For more information, feel free to contact us at http://coldfrontlabs.ca/contact