<?php
$content = $element->content;
?>

<div class="<?php print $classes; ?>">
  <h2><?php print $content['#element']->city_name; ?>: <?php print $content['#element']->city_id; ?></h2>
  <p class="meta">
    <?php print $content['#element']->city_location; ?><br />
    <?php print $content['#element']->city_pop; ?><br />
    <?php print $content['#element']->city_state; ?>
  </p>
</div>