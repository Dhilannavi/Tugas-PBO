<?php
function template_header(){
    echo <<<EOT
        <nav class="navtop">
        <div>
            <h1>OOP</h1>
            <a href="student-view.php">Home View</a>
            <a href="student-add.php">Add Data</a>
        </div>
        </nav>
    EOT;
}
?>