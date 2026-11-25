#!/bin/bash
# Automated Deployment & Rollback Script (Chapter 7)

ENVIRONMENT=${1:-staging}
APP_BINARY="./build/GradeSystem"
DEPLOY_DIR="./environments/${ENVIRONMENT}/app"
BACKUP_DIR="./environments/${ENVIRONMENT}/backup"

echo "=========================================="
echo " Deploying GradeSystem to: ${ENVIRONMENT^^}"
echo "=========================================="
mkdir -p "$DEPLOY_DIR" "$BACKUP_DIR"

# Step 1: Backup current live version (if one exists)
if [ -f "$DEPLOY_DIR/GradeSystem" ]; then
    echo "[Step 1] Creating backup of current version..."
    cp "$DEPLOY_DIR/GradeSystem" "$BACKUP_DIR/GradeSystem.bak"
else
    echo "[Step 1] First-time deployment. No backup needed."
fi

# Step 2: Deploy new compiled binary
echo "[Step 2] Copying new version to $DEPLOY_DIR..."
cp "$APP_BINARY" "$DEPLOY_DIR/GradeSystem"
chmod +x "$DEPLOY_DIR/GradeSystem"

# Step 3: Post-deployment Health Check
echo "[Step 3] Running post-deployment health check..."
"$DEPLOY_DIR/GradeSystem" --health-check

if [ $? -ne 0 ]; then
    echo "[ALERT] Health check FAILED! Rolling back to backup..."
    if [ -f "$BACKUP_DIR/GradeSystem.bak" ]; then
        cp "$BACKUP_DIR/GradeSystem.bak" "$DEPLOY_DIR/GradeSystem"
        echo "[ROLLBACK] Previous version restored."
    fi
    exit 1
fi

echo "[SUCCESS] ${ENVIRONMENT^^} deployment passed health check!"
"$DEPLOY_DIR/GradeSystem"
exit 0
