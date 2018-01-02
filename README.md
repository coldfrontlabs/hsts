HTTP Strict Transport Security
==============================

This module inserts an HTTP Strict Transport Security header into your Backdrop
site's pages. For more information regarding HTTP Strict Transport Security, see
http://en.wikipedia.org/wiki/HTTP_Strict_Transport_Security

This method of header insertion is useful for those who can't change their web
server's configuration to include the HSTS header.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- Visit the configuration page under Administration > Configuration > Security >
  HTTP Strict Transport Security Settings (admin/config/security/hsts) and alter
  the default settings as desired.

- If your server is behind an SSL terminated proxy, you can set the HSTS headers
  to be included on HTTP responses as well. Please be advised, however, that the
  HSTS specification states that the STS headers should only be included on
  secure connections.

Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/hsts/issues

Current Maintainers
-------------------

- Jerry Hudgins (https://github.com/jerry-hudgins/)

Credits
-------

- Ported to Backdrop CMS by Jerry Hudgins (https://github.com/jerry-hudgins/).
- Originally written for Drupal by Mathew Winstone (https://github.com/minorOffense/).

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
