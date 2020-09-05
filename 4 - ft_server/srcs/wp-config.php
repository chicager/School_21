<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpress_user' );

/** MySQL database password */
define( 'DB_PASSWORD', '12345' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 * 
 */
    define('AUTH_KEY',         '2ojcTNkg`}]v<Na/a{sS/n!X*<|`CUt|i0y<Sv-YGl$N8~<or|r +b^_Y;?Tdg+h');
    define('SECURE_AUTH_KEY',  'vseyK:|F`].cuP1vNrzdUUUk4}F(z%d,oty&tJU{L;5`EBP]03_rq^n#@kz%hW!A');
    define('LOGGED_IN_KEY',    'A:ap7Tpg_xLf&m38SFk]JjtjWVx%6p|7jh*5)wm{vQUd+FL&Pg#(DMa/*ePNsTO ');
    define('NONCE_KEY',        '&D`vVmKO;q3{{65+QtR01?G=r;;c~c(p.J|z|NBVt]4qD]4G_v?@bL0B6sL$V5k5');
    define('AUTH_SALT',        ':YEow9}V=n|gaFG+%b8tqbZPBG#l_l=4j$|-/X>Uo)wxG#k?x{%_Opz#dm}MujTE');
    define('SECURE_AUTH_SALT', '(]gscw|5>-[Yp~>.$2g$@=;O8 )a/KcEd:Zef8&~63L;4_RLseMJW%_]W?H_{zPI');
    define('LOGGED_IN_SALT',   'iT-=pjK;&{[M!PAtCXz-@=/@2~=.K-Q!B|LUNT#.Af kk~Qh`Cb8UHlv5fUkl@1F');
    define('NONCE_SALT',       'EZ|6VvLyaggIk8u;f^-Nt2xITs4_OusJe;Gw]kGv.?.>xcmnX,|hz$$~Y({hK?fA');

    $table_prefix = 'wp_';

    define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
    if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
    }

/** Sets up WordPress vars and included files. */
	require_once ABSPATH . 'wp-settings.php';
?>
